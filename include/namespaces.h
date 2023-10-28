#pragma once

// #ifndef NAMESPACES_H
// #define NAMESPACES_H


namespace CurrentNote
{
    extern int noteNumber;
    extern int pianoNote;
    extern std::string noteName;
    extern double frequency;
}


namespace JsonValues
{
    extern Json::Value intermediateNote;
    extern Json::Value noteArray;
}

namespace Settings
{
    extern double defaultA4Freq;
    extern bool generateDefault;
};

// #endif