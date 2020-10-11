#pragma once

#include <string>
#include <map>
#include <fstream>

class JsonParser
{
public:
    static std::map<std::string, std::string> Parse(const char *fileName);
    static std::map<std::string, std::string> Parse(std::ifstream &fileStream);
    static std::map<std::string, std::string> Parse(std::string fileContent);
};