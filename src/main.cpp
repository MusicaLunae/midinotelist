#include <iostream>
#include <json/json.h>

// #include "namespaces.h"
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

/*
Json::Value midiNoteGenerator(int midiNote)
{
    Json::Value allMidiNotes;
    return allMidiNotes;
}
*/

Json::Value generateMidiNote(int note)
{
    double baseFreq = 440.00;
    CurrentNote::frequency = calculateFrequency((double)note, baseFreq);
    std::cout << "CurrentNote::frequency is: " << CurrentNote::frequency << std::endl;
    return note;
}



void createNoteArray()
{
    int octaveNumber = -1;
    for (int i = 0; i < 128 ; i++)
    {
        // midiNoteGenerator(i);

        Json::Value noteArray[i] = generateMidiNote(i);

        int j = i + 1;
    }
}

int main()
{

    // iterator();

    readJson();

    return 0;
}