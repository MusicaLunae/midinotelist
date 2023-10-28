#include <fstream>
#include <iostream>
#include <json/json.h>

int writeJsonArray(Json::Value noteArray)
{
    std::fstream writeOutput;
    writeOutput.open("./notetable.json", std::fstream::out);
    writeOutput << noteArray;

    writeOutput.close();
    std::cout << "\033[1;31mOutput succesfully written to notetable.json\033[0m" << std::endl;
    return 0;

}