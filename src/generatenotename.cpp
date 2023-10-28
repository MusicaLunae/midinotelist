#include <iostream>
#include <json/json.h>

#include "namespaces.h"

std::string generateNoteName(int octave, int modulo)
{
    std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    CurrentNote::noteName = noteNames[modulo] + std::to_string(octave);
    return CurrentNote::noteName;
}