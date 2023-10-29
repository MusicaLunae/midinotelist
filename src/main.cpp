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

        std::cout << "\033[1;31mFile generated.\033[0m" << std::endl << std::endl;
    }
}

int main()
{
    Settings::exitVar = false;

    do
    {
        readSettings();
        generateDefault();

        int mode = setMode();
        switch(mode)
        {
            case -1:
                wrongInput();
                break;
            
            case 3:
                Settings::exitVar = true;
                break;

            case 1:
                generateDefault();
                break;
            
            case 2:
                writeJsonArray(JsonValues::noteArray);
                break;
        }
        continue;
    }
    while (Settings::exitVar == false);

    return 0;
}