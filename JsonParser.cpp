#include "JsonParser.h"
#include <iostream>

std::map<std::string, std::string> JsonParser::Parse(const char *fileName)
{
    std::string fName(fileName);
    std::ifstream fstream("units/" + fName);

    return JsonParser::Parse(fstream);
}

std::map<std::string, std::string> JsonParser::Parse(std::ifstream &fileStream)
{
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
    return JsonParser::Parse(fstream);
}
