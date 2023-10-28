#include <json/json.h>

namespace CurrentNote
{
    int noteNumber{};
    int pianoNote{};
    std::string noteName{};
    double frequency{};
}

namespace JsonValues
{
    Json::Value intermediateNote;
    Json::Value noteArray;
}

namespace Settings
{
    double defaultA4Freq{};
    bool generateDefault{};
    double baseFreq{};
}