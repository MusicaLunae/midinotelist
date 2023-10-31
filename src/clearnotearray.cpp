#include <iostream>
#include <json/json.h>

void clearNoteList(Json::Value noteList)
{
    noteList.empty();
    std::cout << noteList;
}