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
    // open the settings file (JSON)
    std::ifstream ifs("settings.json");
    Json::Reader settingsReader;
    Json::Value obj;
    settingsReader.parse(ifs, obj);

    Settings::defaultA4Freq = obj["default-A4"].asDouble();
    std::cout << "Default A4 frequency: " << Settings::defaultA4Freq << std::endl;
    if (obj["generate-default"].asBool() == 1)
    {
        Settings::generateDefault = true;
    }
    else
    {
        Settings::generateDefault = false;
    }

}