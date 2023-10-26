#include <json/json.h>

namespace JsonValues
{
    Json::Value intermediateNote;
    Json::Value noteArray;
}

namespace Settings
{
    double defaultA4Freq{};
    bool generateDefault{};
}

namespace Output
{
    Json::Value noteArray;
    double frequency{};
}
