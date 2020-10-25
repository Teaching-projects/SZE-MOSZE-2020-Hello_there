#include "JsonParser.h"
#include <iostream>
#include <streambuf>

std::map<std::string, std::string> JsonParser::Parse(const char *fileName)
{
    std::string fName = "units/" + std::string(fileName);
    std::ifstream fstream(fName);
    if (!fstream.good())
        throw "problem with file stream";

    return JsonParser::Parse(fstream);
}

std::map<std::string, std::string> JsonParser::Parse(std::ifstream &fileStream)
{
    if (!fileStream.good())
        throw "problem with file stream";

    std::string s((std::istreambuf_iterator<char>(fileStream)), std::istreambuf_iterator<char>());
    JsonParser::CheckJsonIntegrity(s);

    fileStream.clear();
    fileStream.seekg(0);
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
    if (!fstream.good())
        throw "problem with file stream";

    std::string s((std::istreambuf_iterator<char>(fstream)),
                  std::istreambuf_iterator<char>());
    JsonParser::CheckJsonIntegrity(s);

    fstream.clear();
    fstream.seekg(0);

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
            if (count != 1)
                throw "invalid json file";
            break;
        case '}':
            if (count != 1)
                throw "invalid json file";
            break;
        case '\"':
            if (count % 2 != 0)
                throw "invalid json file";
            break;
        case ':':
            if (count != symbolCount[','] + 1)
                throw "invalid json file";
            break;
        }
    }
}
