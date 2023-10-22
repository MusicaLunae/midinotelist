#include <iostream>
#include <json/json.h>

#include "namespaces.h"
#include "readsettings.h"

std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};

namespace CurrentNote
{
    int noteNumber{};
    int pianoNote{};
    std::string noteName{};
    double frequency{};
}


Json::Value midiNoteGenerator(int midiNote)
{
    Json::Value allMidiNotes;
    return allMidiNotes;
}



void iterator()
{
    int octaveNumber = -1;
    for (int i = 0; i < 128 ; i++)
    {
        midiNoteGenerator(i);
    }
}

int main()
{

    // iterator();

    readJson();

    return 0;
}