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
	JSON(const std::map<std::string, std::any>&);
	int count(std::string);
	template <typename T>
	T get(const std::string& key)
	{
		return std::any_cast<T>(data[key]);
	}

    static JSON parseFromFile(const char *fileName);
    static JSON parseFromStream(std::ifstream &fileStream);
    static JSON parseFromString(const std::string& fileContent);
	static JSON parse(const std::string&);

	class ParseException : virtual public std::runtime_error
	{
	public:
		explicit ParseException(const std::string& info) : std::runtime_error("Error occured during parsing: " + info) {}
	};

private:
	static bool isFloat(const char&, const char&);
	std::map<std::string, std::any> data;
    static void CheckJsonIntegrity(std::string jsonStr);
};
