#include <fstream>
#include <iostream>
#include <json/json.h>

int writeJsonArray(Json::Value noteArray)
{
    std::fstream writeOutput;
    std::string filename;
    std::cout << "\033[1mPlease specify a filename: \033[0m";
    std::cin >> filename;

    std::string fullPath = "./" + filename;

    std::cout << "\nfull path: " << fullPath << std::endl;

    writeOutput.open(fullPath, std::fstream::out);
    writeOutput << noteArray;

    writeOutput.close();
    std::cout << "\033[1;31mOutput succesfully written to notetable.json\033[0m" << std::endl;
    return 0;

}