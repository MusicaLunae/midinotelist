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

void writeJsonTest()
{
    void enableYAMLCompatibility();
    Json::StyledWriter writer;
    Json::Value newA4Freq;
    std::cout << "new A4 frequency: ";
    std::cin >> newA4Freq;
    std::cout << "crash after std::cin" << std::endl;
    
    switch (newA4Freq.type()) {
        case Json::nullValue: std::cout << "nullValue\n"; break;
        case Json::intValue: std::cout << "intValue\n"; break;
        case Json::uintValue: std::cout << "uintValue\n"; break;
        case Json::realValue: std::cout << "realValue\n"; break;
        case Json::stringValue: std::cout << "stringValue\n"; break;
        case Json::booleanValue: std::cout << "booleanValue\n"; break;
        case Json::arrayValue: std::cout << "arrayValue\n"; break;
        case Json::objectValue: std::cout << "objectValue\n"; break;
        default: std::cout << "wrong type\n"; break;
    }

    std::string dubNewA4Freq = writer.write(newA4Freq);

    std::cout << "newA4Freq:    " << newA4Freq << std::endl;
    std::cout << "dubNewA4Freq: " << dubNewA4Freq << std::endl;

}


void documentationExample()
{
    // create the characters array
    Json::Value ch;
    ch[0]["name"] = "Jabberwock";
    ch[0]["chapter"] = 1;
    ch[1]["name"] = "Cheshire Cat";
    ch[1]["chapter"] = 6;
    ch[2]["name"] = "Mad Hatter";
    ch[2]["chapter"] = 7;

    // create the main object
    Json::Value val;
    val["book"] = "Alice in Wonderland";
    val["year"] = 1865;
    val["characters"] = ch;

    std::cout << val << '\n';
}

void lineBreak()
{
    std::cout << "\n\n==================================\n";
}


int main()
{
    lineBreak();
    readJsonTest();

    lineBreak();
    // writeJsonTest();
    documentationExample();
    return 0;
}