#include <iomanip>
#include <iostream>
#include <json/config.h>
#include <json/json.h>
// #include <sstream>
// #include <stdlib.h>

#include "namespaces.h"
#include "createnotearray.h"
// #include "calculatefrequency.h"
#include "readsettings.h"
#include "printjsonarray.h"
#include "writejsonarray.h"
#include "setmode.h"

void generateDefault()
{
    if (Settings::generateDefault == true)
    {
        double baseFreq = Settings::defaultA4Freq;
        createNoteArray(baseFreq);

        std::cout << "\033[1;31mFile generated.\033[0m";
    }
}

int main()
{
    readJson();
    generateDefault();

    int mode = setMode();
    switch(mode)
    {
        case 1:
            generateDefault();
        
        case 2:
            writeJsonArray(JsonValues::noteArray);
    }

    std::cout << "JSON array: " << std::endl;
    printJsonArray(JsonValues::noteArray);
    writeJsonArray(JsonValues::noteArray);
    return 0;
}