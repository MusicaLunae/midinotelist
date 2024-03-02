#include <cmath>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <json/config.h>
#include <json/json.h>
// #include <sstream>
// #include <stdlib.h>

#include <wx/wxprec.h>
#ifndef WX_PRECOMP
#   include <wx/wx.h>
#endif


#include "namespaces.h"
// #include "createnotearray.h"
// #include "calculatefrequency.h"
// #include "readsettings.h"
// #include "printjsonarray.h"
// #include "setmode.h"
// #include "writejsonarray.h"
// #include "getfrequency.h"
// #include "readjsonarray.h"
// #include "clearnotearray.h"
#include "main.h"
#include "gui.h"


// createnotearray.h
void createNoteArray()
{
    double baseFreq = getFrequency();
    Json::Value null = Json::nullValue;
    int octaveNumber = -1;
    for (int i = 0; i < 128 ; i++)
    {
        // Modulo is for iterating through the note list
        // C is index (modulo) 0, B is index 11
        int modulo = i % 12;
        CurrentNote::pianoNote = i - 20;

        JsonValues::noteArray[i]["note number"] = i;

        // Midi note 21 == piano note 1
        // Piano notes run from 1 to 88 (including), or midi note 21 to 108 (including)
        if (i < 21)
        {
            JsonValues::noteArray[i]["piano note"] = null;
            JsonValues::noteArray[i]["note name"] = null;
        }
        else if (CurrentNote::pianoNote > 88)
        {
            JsonValues::noteArray[i]["piano note"] = null;
            JsonValues::noteArray[i]["note name"] = generateNoteName(octaveNumber, modulo);
        }
        else
        {
            JsonValues::noteArray[i]["piano note"] = CurrentNote::pianoNote;
            JsonValues::noteArray[i]["note name"] = generateNoteName(octaveNumber, modulo);
        }

        JsonValues::noteArray[i]["frequency"] = calculateFrequency(i, baseFreq);

        if (modulo == 11)
        {
            octaveNumber++;
        }
    }
}

void createDefaultArray(double baseFreq)
{
    Json::Value null = Json::nullValue;
    int octaveNumber = -1;
    for (int i = 0; i < 128 ; i++)
    {
        // Modulo is for iterating through the note list
        // C is index (modulo) 0, B is index 11
        int modulo = i % 12;
        CurrentNote::pianoNote = i - 20;

        JsonValues::noteArray[i]["note number"] = i;

        // Midi note 21 == piano note 1
        // Piano notes run from 1 to 88 (including), or midi note 21 to 108 (including)
        if (i < 21)
        {
            JsonValues::noteArray[i]["piano note"] = null;
            JsonValues::noteArray[i]["note name"] = null;
        }
        else if (CurrentNote::pianoNote > 88)
        {
            JsonValues::noteArray[i]["piano note"] = null;
            JsonValues::noteArray[i]["note name"] = generateNoteName(octaveNumber, modulo);
        }
        else
        {
            JsonValues::noteArray[i]["piano note"] = CurrentNote::pianoNote;
            JsonValues::noteArray[i]["note name"] = generateNoteName(octaveNumber, modulo);
        }

        JsonValues::noteArray[i]["frequency"] = calculateFrequency(i, baseFreq);

        if (modulo == 11)
        {
            octaveNumber++;
        }
    }
}



// calculatefrequency.h
double calculateFrequency(double noteNum, double baseFrequency)
{
    double exponent = ((noteNum - 69) / 12);
    double freq = baseFrequency * pow(2, exponent);
    return freq;
}


// generatenotename.h
std::string generateNoteName(int octave, int modulo)
{
    std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    CurrentNote::noteName = noteNames[modulo] + std::to_string(octave);
    return CurrentNote::noteName;
}



// readsettings.h
void readSettings()
{
    // Open the settings file (JSON)
    std::ifstream ifs("settings.json");
    Json::Reader settingsReader;
    Json::Value obj;
    settingsReader.parse(ifs, obj);

    // Import the settings
    Settings::defaultA4Freq = obj["default-A4"].asDouble();
    std::cout << "Default A4 frequency: " << Settings::defaultA4Freq << std::endl;
    if (obj["generate-default"].asBool() == 1)
    {
        Settings::generateDefault = true;
    }
    else
    {
        Settings::generateDefault = false;
    }

}



// printjsonarray.h
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




// writejsonarray.h
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



// setmode.h
int setMode()
{
    char mode{};
    std::cout << "\033[1;34mPlease select a mode: \033[0m" << std::endl;
    std::cout << "\033[1m'c': Clear the generated note list\033[0m" << std::endl;
    std::cout << "\033[1m'g': Generate a note list\033[0m" << std::endl;
    std::cout << "\033[1m'p': Print out the generated note list\033[0m" << std::endl;
    std::cout << "\033[1m'r': Read a note list from disk\033[0m" << std::endl;
    std::cout << "\033[1m'w': Write out a file\033[0m" << std::endl;
    std::cout << "\033[1m'x': Exit the program\033[0m" << std::endl;

    std::cin >> mode;
    int returnMode;
    
    const std::string validModes = "gwxprc";
    for (int i = 0; i < validModes.length(); i++)
    {
        if (validModes[i] == mode)
        {
            switch(mode)
            {
                case 'g':
                    returnMode = 1;
                    break;

                case 'w':
                    returnMode = 2;
                    break;

                case 'x':
                    returnMode = 3;
                    break;

                case 'p':
                    returnMode = 4;
                    break;

                case 'r':
                    returnMode = 5;
                    break;
                
                case 'c':
                    returnMode = 6;
                    break;
            }
            break;
        }
        else
        {
            returnMode = -1;
            continue;
        }
    }
    return returnMode;
}

void wrongInput()
{
    std::cout << "\033[1;31mInvalid input.\033[0m" << std::endl;
}




// getfrequency.h
double getFrequency()
{
    double freq{};
    std::cout << "\033[1;32mPlease enter a frequency to use: ";
    std::cin >> freq;
    return freq;
}



// readjsonarray.h
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



// clearnotearray.h
void clearNoteList(Json::Value noteList)
{
    noteList.empty();
    std::cout << noteList;
}



/* #####   PRE-GUI   #####
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
*/

IMPLEMENT_APP(MainApp)

bool MainApp::OnInit()
{
    MainFrame *MainWin = new MainFrame(_T("MidiNoteList"))
}