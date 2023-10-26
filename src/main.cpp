#include <iostream>
#include <json/json.h>

#include "namespaces.h"
#include "calculatefrequency.h"
#include "readsettings.h"



std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

namespace CurrentNote
{
    int noteNumber{};
    int pianoNote{};
    std::string noteName{};
    double frequency{};
}



Json::Value generateMidiNote(int note)
{
    double baseFreq = 440.00;
    CurrentNote::frequency = calculateFrequency((double)note, baseFreq);
    std::cout << "CurrentNote::frequency is: " << CurrentNote::frequency << std::endl;

    JsonValues::intermediateNote[note]["note number"] = note;

    return JsonValues::intermediateNote;
}



void createNoteArray()
{
    std::string null = "null";
    int octaveNumber = -1;
    for (int i = 0; i < 128 ; i++)
    {
        if (i < 21)
        {
            JsonValues::noteArray[i]["note name"] = i;
            // JsonValues::noteArray[i]["piano note"] = null.asNull();
        }

        int j = i + 1;
    }
}

int main()
{

    // iterator();

    readJson();
    generateMidiNote(65);

    return 0;
}