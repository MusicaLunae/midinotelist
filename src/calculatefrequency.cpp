#include <cmath>

double calculateFrequency(double noteNum, double baseFrequency)
{
    double exponent = ((noteNum - 69) / 12);
    double freq = baseFrequency * pow(2, exponent);
    return freq;
}