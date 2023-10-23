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

    Settings::defaultA4Freq = obj["A4-freq"].asDouble();
    std::cout << "defaultA4Freq: " << Settings::defaultA4Freq << std::endl;

}