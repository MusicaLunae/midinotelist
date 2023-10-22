#include <fstream>
#include <iostream>
#include <json/json.h>

#include "namespaces.h"
#include "readsettings.h"

/* bool checkGenerateDefault()
{
    Settings::generateDefault
} */

void readJson()
{
    Settings::generateDefault = false;
    std::cout << "generate default has been set to: " << Settings::generateDefault << std::endl;
    std::ifstream ifs("settings.json");
    Json::Reader settingsReader;
    Json::Value obj;
    settingsReader.parse(ifs, obj);
    if (obj["generate-default"].asBool() == 1)
    {
        Settings::generateDefault = true;
    }
    else
    {
        Settings::generateDefault = false;
    }
    std::cout << "generate default has been set to: " << Settings::generateDefault << std::endl;

}