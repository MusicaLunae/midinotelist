#include <json/json.h>

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
