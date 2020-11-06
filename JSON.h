#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <iterator>
#include <any>

class JSON
{
public:
	JSON(const std::map<std::string, std::any> &);
	int count(std::string);
	template <typename T>
	 T get(const std::string &key) const
	{
		std::string value = std::any_cast<std::string>(data[key]);
		std::any converted;

		if (std::is_same<T, int>::value)
		{
			converted = (std::stoi(value));
		}
		else if (std::is_same<T, float>::value)
		{
			converted = (std::stof(value));
		}
		else if (std::is_same<T, std::string>::value)
		{
			converted = value;
		}

		return std::any_cast<T>(converted);
	}
	friend bool operator==(const JSON& lhs, const JSON& rhs);
	static JSON parseFromFile(const char *fileName);
	static JSON parseFromStream(std::ifstream &fileStream);
	static JSON parseFromString(const std::string &fileContent);
	static JSON parse(const std::string &);

	class ParseException : virtual public std::runtime_error
	{
	public:
		explicit ParseException(const std::string &info) : std::runtime_error("Error occured during parsing: " + info) {}
	};

private:
	static bool isFloat(const char &, const char &);
	std::map<std::string, std::any> data;
	static void CheckJsonIntegrity(std::string jsonStr);
};
