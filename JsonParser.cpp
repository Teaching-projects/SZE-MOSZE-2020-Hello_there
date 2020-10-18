#include "JsonParser.h"
#include <iostream>
#include <streambuf>
#include <filesystem>

std::map<std::string, std::string> JsonParser::Parse(const char *fileName)
{
    std::string fName(fileName);
    std::ifstream fstream("units/" + fName);

    std::string s((std::istreambuf_iterator<char>(fstream)),
                  std::istreambuf_iterator<char>());
    JsonParser::CheckJsonIntegrity(s);

    return JsonParser::Parse(fstream);
}

std::map<std::string, std::string> JsonParser::Parse(std::ifstream &fileStream)
{
    std::string s((std::istreambuf_iterator<char>(fileStream)),
                  std::istreambuf_iterator<char>());
    JsonParser::CheckJsonIntegrity(s);

    std::map<std::string, std::string> myMap;
    char c;
    while (fileStream.get(c))
    {
        if (c == '\"')
        {
            std::string key = "";
            for (fileStream.get(c); c != '\"'; fileStream.get(c))
                key += c;

            for (fileStream.get(c); c == ':' || c == ' ' || c == '\"'; fileStream.get(c)) // skip until val starts
                ;

            std::string val = "";
            for (; c != '\"' && c != '\n' && c != ','; fileStream.get(c))
                val += c;

            myMap[key] = val;
        }
    }

    return myMap;
}

std::map<std::string, std::string> JsonParser::Parse(std::string fileName)
{
    std::ifstream fstream("units/" + fileName);

    std::string s((std::istreambuf_iterator<char>(fstream)),
                  std::istreambuf_iterator<char>());
    JsonParser::CheckJsonIntegrity(s);

    std::map<std::string, std::string> myMap;
    for (std::string::size_type i = 0; i < s.size(); i++)
    {
        if (s[i] == '\"')
        {
            std::string key = "";
            for (i++; s[i] != '\"'; i++)
                key += s[i];

            for (i++; s[i] == ':' || s[i] == ' ' || s[i] == '\"'; i++) // skip until val starts
                ;

            std::string val = "";
            for (; s[i] != '\"' && s[i] != '\n' && s[i] != ','; i++)
                val += s[i];

            myMap[key] = val;
        }
    }

    return myMap;
}

void JsonParser::CheckJsonIntegrity(std::string jsonStr)
{
    int numOfSymbols = 5;
    char symbols[numOfSymbols] = {'{', '}', '\"', ':', ','};

    std::map<char, int> symbolCount;
    symbolCount['{'] = 0;
    symbolCount['}'] = 0;
    symbolCount['\"'] = 0;
    symbolCount[':'] = 0;
    symbolCount[','] = 0;

    int expectedCount[numOfSymbols] = {1, 1, 8, 3, 2};

    for (std::string::size_type i = 0; i < jsonStr.size(); i++)
    {
        if (symbolCount.count(jsonStr[i]))
            symbolCount[jsonStr[i]]++;
    }

    for (int i = 0; i < numOfSymbols; i++)
    {
        char symbol = symbols[i];
        if (symbolCount[symbol] != expectedCount[symbol])
            throw symbolCount[symbol] + " '" + std::to_string(symbol) + "' instead of " + std::to_string(expectedCount[i]);
    }
}
