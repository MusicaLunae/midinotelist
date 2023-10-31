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
    Json::Value loadedList;
}

namespace Settings
{
    double baseFreq{};
    double defaultA4Freq{};
    bool exitVar{};
    bool generateDefault{};
}