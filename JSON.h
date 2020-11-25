#pragma once
#include <iostream>
#include <string>
#include <map>
#include <fstream>
#include <variant>
#include <list>

class JSON
{
public:
	typedef std::variant<int, double, std::string> valueVariant;
	typedef std::list<valueVariant> list;
	typedef std::variant<int, double, std::string, list> listedValueVariant;
	JSON(std::map<std::string, listedValueVariant> data);
	int count(std::string);
	template <typename T>
	T get(const std::string &key)
    {
        return std::get<T>(data[key]);
    }
	static bool compareJSON(JSON &j1, JSON &j2);

	static JSON parseFromFile(const std::string& fileName);
	static JSON parseFromStream(std::istream& fileStream);
	static JSON parseFromString(const std::string &fileContent);
	static JSON parse(const std::string &);

	class ParseException : virtual public std::runtime_error
	{
	public:
		explicit ParseException(const std::string &info) : std::runtime_error("Error occured during parsing: " + info) {}
	};

private:
	std::map<std::string, listedValueVariant> data;
	static void CheckJsonIntegrity(std::string jsonStr);
	static valueVariant simpleTypeParse(const std::string& match);
	static list arrayParse(const std::string& match);
	template <class... Args>
	struct variant_cast_proxy
	{
		std::variant<Args...> v;

		template <class... ToArgs>
		operator std::variant<ToArgs...>() const
		{
			return std::visit(
				[](auto&& arg) -> std::variant<ToArgs...> { return arg; },
				v);
		}
	};

	template <class... Args>
	static auto variant_cast(const std::variant<Args...>& v) -> variant_cast_proxy<Args...>
	{
		return { v };
	
	}
};
