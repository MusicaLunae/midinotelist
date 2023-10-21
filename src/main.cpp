#include <iostream>
#include <json/json.h>

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
    Json::Value midiNoteJson;
    
    return midiNoteJson;
}

void iterator()
{
    for (int i = 0; i < 128 ; i++)
    {
        
    }
}

int main()
{

    iterator();

    return 0;
}