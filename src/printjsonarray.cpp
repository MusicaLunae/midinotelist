#include <iomanip>
#include <iostream>
#include <json/json.h>

void printJsonArray(Json::Value noteList)
{
    for (int i = 0; i < 128; i++)
    {
        // std::cout << "Note number: ";
        std::cout << "\033[1;32mNote number:\033[0m " << noteList[i]["note number"].asString() << std::endl;
        std::cout << "\033[1;32mPiano note :\033[0m " << noteList[i]["piano note"].asString() << std::endl;
        std::cout << "\033[1;32mNote name  :\033[0m " << noteList[i]["note name"].asString() << std::endl;
        std::cout << std::fixed << std::setprecision(2) << "\033[1;34mFrequency  :\033[0m " << noteList[i]["frequency"].asDouble() << std::endl << std::endl;
    }
}

void printOneNote(Json::Value noteList, int i)
{
    std::cout << "\033[1;32mNote number:\033[0m " << noteList[i]["note number"].asString() << std::endl;
    std::cout << "\033[1;32mPiano note :\033[0m " << noteList[i]["piano note"].asString() << std::endl;
    std::cout << "\033[1;32mNote name  :\033[0m " << noteList[i]["note name"].asString() << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\033[1;34mFrequency  :\033[0m " << noteList[i]["frequency"].asDouble() << std::endl << std::endl;

}