/**
* \class JsonParser
*
* this class reads data from json files to create units
*
* \author gfellnerm
* \date 2020_10_31
*/

#pragma once

#include <string>
#include <map>
#include <fstream>

class JsonParser
{
public:
    /**
     * \brief reads unit data from json file and returns it as map
     * \param fileName the name of the json file
    */
    static std::map<std::string, std::string> Parse(const char *fileName);

    /**
     * \brief reads unit data from json file and returns it as map
     * \param fileStream stream of the json file
    */
    static std::map<std::string, std::string> Parse(std::ifstream &fileStream);

    /**
     * \brief reads unit data from json file and returns it as map
     * \param fileContent contents of the json file as one big string
    */
    static std::map<std::string, std::string> Parse(std::string fileContent);
    static bool CompareMaps(std::map<std::string, std::string> m1, std::map<std::string, std::string> m2);

private:
    /**
     * \brief throws exception when basic json syntax rules aren't met
     * \param jsonStr contents of the json file as one big string
    */
    static void CheckJsonIntegrity(std::string jsonStr);
};