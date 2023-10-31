#include <fstream>
#include <iostream>
#include <json/json.h>

#include "namespaces.h"

void readJsonArray()
{
    std::string filename = "";
    std::cout << "\033[1mPlease specify a file: \033[0m";
    std::cin >> filename;

    std::ifstream ifs(filename);
    Json::Reader fileReader;
    Json::Value obj;

    std::cout << "\nthe file loaded was " << filename << std::endl;

    ifs >> JsonValues::loadedList;

}