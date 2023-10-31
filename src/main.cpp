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
#include "getfrequency.h"
#include "readjsonarray.h"
#include "clearnotearray.h"

int main()
{
    Settings::exitVar = false;

    // main program loop
    do
    {
        readSettings();
        if (Settings::generateDefault == true)
        {
            double baseFreq = Settings::defaultA4Freq;
            createDefaultArray(baseFreq);
            std::cout << "\033[1;31mDefault note list generated.\033[0m" << std::endl << std::endl;
        }

        int mode = setMode();
        switch(mode)
        {
            case -1:
                wrongInput();
                break;

            case 1: // generate the array (g)
                createNoteArray(); 
                std::cout << "\033[1;31mNote list generated.\033[0m\n" << std::endl;
                break;
            
            case 2: // write the array to disk (w)
                writeJsonArray(JsonValues::noteArray);
                break;

            case 3: // exit the program (x)
                Settings::exitVar = true;
                break;

            case 4: // print the loaded/generated array (p)
                printJsonArray(JsonValues::noteArray);
                break;

            case 5: // read an array from disk (r)
                readJsonArray();
                break;

            case 6: // clear the currently loaded array (c)
                clearNoteList(JsonValues::noteArray);
                break;
        }
        continue;
    }
    while (Settings::exitVar == false);

    return 0;
}