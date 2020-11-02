#include "JSON.h"
#include <iostream>
#include <streambuf>
#include <regex>

JSON::JSON(const std::map<std::string, std::any>& mymap) : data(mymap)
{
}

int JSON::count(std::string s)
{
	return data.count(s);
}

JSON JSON::parseFromFile(const char *fileName)
{
    std::string fName = std::string(fileName);
    std::ifstream fstream(fName);
    if (!fstream.good())
        throw "Problem with file!";

	return parseFromStream(fstream);
}

JSON JSON::parseFromStream(std::ifstream &fileStream)
{
    if (!fileStream.good())
        throw "problem with file stream";

    std::string s((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
	return parse(s);
}

JSON JSON::parseFromString(const std::string& string)
{
	return parse(string);
}

JSON JSON::parse(const std::string& string)
{
	//JSON::CheckJsonIntegrity(string);
	static const std::regex Regex("\\s*\"([a-z_]*)\"\\s*:\\s*([0-9]*\\.?[0-9]+|\"[\\w\\s\\./]+\")\\s*([,}])\\s*");

	std::string worker(string);
	std::smatch matches;
	std::map<std::string, std::any> myMap;

	while (std::regex_search(worker, matches, Regex))
	{

		if (matches.size() == 4)
		{

			std::string value = matches[2].str();
			if (value.at(0) == '"')
			{
				value.erase(value.begin());
				value.erase(value.end() - 1);
				myMap[matches[1]] = value;
			}
			else if (value.find_first_of('.') != std::string::npos)
			{
				myMap[matches[1]] = stof(value);
			}
			else
			{
				myMap[matches[1]] = stoi(value);
			}
		}
		worker = matches.suffix();
	}

	if (worker.length())
	{
		throw JSON::ParseException("Key or value missing!");
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

    for (int i = 0; i < sizeof(symbols) - 1; i++)
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
