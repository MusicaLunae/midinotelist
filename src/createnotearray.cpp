#include <iostream>
#include <json/json.h>

#include "namespaces.h"
#include "calculatefrequency.h"
#include "generatenotename.h"

void createNoteArray(double baseFreq)
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