#include <iostream>
#include <fstream>
#include <json/json.h>


void readJsonTest()
{
    std::ifstream ifs("testfile.json");
    Json::Reader reader;
    Json::Value obj;
    std::string defaultStartTable;
    reader.parse(ifs, obj);
    if (obj["generate-default-table-on-startup"].asBool() == 1)
    {
        defaultStartTable = "true";
    }
    else
    {
        defaultStartTable = "false";
    }
    std::cout << "A4-freq: " << obj["A4-freq"].asDouble() << "Hz" << std::endl;
    std::cout << "generate default table on startup: " << obj["generate-default-table-on-startup"].asBool() << std::endl;
    std::cout << "(this means that the setting is set to " << defaultStartTable << ")" << std::endl;

}

int main()
{

    readJsonTest();

    return 0;
}