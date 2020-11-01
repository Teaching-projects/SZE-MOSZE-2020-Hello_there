#pragma once

#include <string>
#include <map>
#include <fstream>

class JSON
{
public:
    static std::map<std::string, std::string> parseFromFile(const char *fileName);
    static std::map<std::string, std::string> parseFromFile(std::ifstream &fileStream);
    static std::map<std::string, std::string> parseFromFile(std::string fileContent);

private:
    static void CheckJsonIntegrity(std::string jsonStr);
};