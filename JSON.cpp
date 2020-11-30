#include "JSON.h"
#include <iostream>
#include <streambuf>
#include <regex>


JSON::JSON(std::map<std::string, listedValueVariant> data) : data(data) {};

int JSON::count(std::string s)
{
	return data.count(s);
}

bool JSON::compareJSON(JSON &lhs, JSON &rhs)
{
	if (lhs.get<std::string>("name") == rhs.get<std::string>("name") &&
		lhs.get<int>("health_points") == rhs.get<int>("health_points") &&
		lhs.get<int>("damage") == rhs.get<int>("damage") &&
		lhs.get<int>("defense") == rhs.get<int>("defense") &&
		lhs.get<double>("attack_cooldown") == rhs.get<double>("attack_cooldown"))
	{
		return true;
	}
	return false;
}

JSON JSON::parseFromFile(const std::string &fileName)
{
	std::ifstream file(fileName);
	if (!file.good())
		throw "Problem with file";

	return parseFromStream(file);
}

JSON JSON::parseFromStream(std::istream &fileStream)
{
	if (!fileStream.good())
		throw "Problem with file stream";

	std::string s(std::string(std::istreambuf_iterator<char>(fileStream), {}));
	return parse(s);
}

JSON JSON::parseFromString(const std::string &string)
{
	return parse(string);
}

JSON JSON::parse(const std::string &string)
{
	JSON::CheckJsonIntegrity(string);
	static const std::regex Regex("\\s*\"([a-z_]*)\"\\s*:\\s*([0-9]*\\.?[0-9]+|\"[\\w\\s\\.\\/]+\")?(\\[([\\S\\s]*)\\])?\\s*([,}])\\s*");

	bool last = false;
	std::string worker(string);
	std::smatch matches;
	std::map<std::string, listedValueVariant> myMap;

	while (std::regex_search(worker, matches, Regex))
	{
		if (last)
		{
			throw JSON::ParseException("Data after closing tag");
		}

		if(matches.size() == 6)
		{
			if (matches[5].str() == "}")
			{
				last = true;
			}

			if (matches[2].str().size() > 0)
			{
			myMap[matches[1]] = variant_cast(simpleTypeParse(matches[2]));
			}
			else
			{
				myMap[matches[1]] = arrayParse(matches[4]);
			}
		}
		worker = matches.suffix();
	}

	if (worker.length() > 0)
	{
		throw JSON::ParseException("Key or value missing");
	}

	return JSON(myMap);
}

void JSON::CheckJsonIntegrity(std::string jsonStr)
{
	char symbols[5] = {'{', '}', '\"', ':', ','};

	std::map<char, int> symbolCount;
	symbolCount['{'] = 0;
	symbolCount['}'] = 0;
	symbolCount['\"'] = 0;
	symbolCount[':'] = 0;
	symbolCount[','] = 0;

	for (std::string::size_type i = 0; i < jsonStr.size(); i++)
	{
		if (symbolCount.find(jsonStr[i]) != symbolCount.end())
			symbolCount[jsonStr[i]]++;
	}

	for (int i = 0; i < sizeof(symbols) / sizeof(symbols[0]) - 1; i++)
	{
		char count = symbolCount[symbols[i]];
		switch (symbols[i])
		{
		case '{':
		case '}':
			if (count != 1)
				throw "invalid json file";
			break;
		case '\"':
			if (count % 2 != 0)
				throw "invalid json file";
			break;
		default:

			break;
		}
	}
}
JSON::valueVariant JSON::simpleTypeParse(const std::string& match)
{
	if (match.at(0) == '"')
	{
		std::string value = match;
		value.erase(value.begin());
		value.erase(value.end() - 1);
		return value;
	}

	if (match.find_first_of('.') != std::string::npos)
	{
		return stod(match);
	}
	return stoi(match);
}
JSON::list JSON::arrayParse(const std::string& match)
{
	static const std::regex Regex("\\s*([0-9]*\\.?[0-9]+|\"[\\w\\s\\.\\/]+\")\\s*(,)?\\s*");

	std::string worker(match);
	std::smatch matches;
	bool hadComma = true;
	std::list<valueVariant> l;

	while (hadComma && std::regex_search(worker, matches, Regex))
	{

		if (matches.size() == 3)
		{
			l.emplace_back(simpleTypeParse(matches[1]));

			hadComma = matches[2] == ",";
		}
		worker = matches.suffix();
	}

	if (worker.length() > 0 || hadComma)
	{
		throw JSON::ParseException("Invalid array");
	}

	return l;
}