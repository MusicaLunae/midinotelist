#include <iostream>
#include <json/config.h>
#include <json/json.h>
#include <sstream>

#include "namespaces.h"
#include "calculatefrequency.h"
#include "readsettings.h"


namespace CurrentNote
{
    int noteNumber{};
    int pianoNote{};
    std::stringstream noteName{};
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

std::string generateNoteName(int octave, int modulo)
{
    std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    CurrentNote::noteName = noteNames[modulo] << std::to_string(octave);
    return CurrentNote::noteName.str();
}


void createNoteArray(double baseFreq)
{
    Json::Value null = Json::nullValue;
    int octaveNumber = -1;
    for (int i = 0; i < 128 ; i++)
    {
        int modulo = i % 12;
        CurrentNote::pianoNote = i - 20;
        if (i < 21)
        {
            JsonValues::noteArray[i]["note number"] = i;
            JsonValues::noteArray[i]["piano note"] = null;
            JsonValues::noteArray[i]["note name"] = null;
            JsonValues::noteArray[i]["frequency"] = calculateFrequency(i, baseFreq);
        }
        else if (CurrentNote::pianoNote > 88)
        {
            JsonValues::noteArray[i]["note number"] = i;
            JsonValues::noteArray[i]["piano note"] = null;
            JsonValues::noteArray[i]["note name"] = generateNoteName(octaveNumber, modulo);
        }

        int j = i + 1;
    }
}

void generateDefault()
{
    if (Settings::generateDefault == true)
    {
        double baseFreq = Settings::defaultA4Freq;    
    }
}

int main()
{

    // iterator();

    readJson();
    generateDefault();

    generateMidiNote(65);

    return 0;
}