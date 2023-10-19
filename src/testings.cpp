#include <iostream>
#include <iomanip>
#include <fstream>
#include <cmath>

double baseFreq = 440.00;
std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
std::ofstream outputFile;

double calculateFrequency(double noteNum, double baseFrequency)
{
    double exponent = ((noteNum - 69) / 12);
    double freq = baseFrequency * pow(2, exponent);
    return freq;
}

double getFreq()
{
    double frequency{};
    std::cout << "Please enter the desired A4 frequency: ";
    std::cin >> frequency;
    std::cout << "\nYou entered: " << frequency << std::endl;
    return frequency;
}

void fileOpen()
{
    outputFile.open("outputlist");
}

void calcerLoop()
{
    double baseFrequency = getFreq();
    std::cout << "\n\n";
    
    for(int i = 0; i < 128; i++)
    {
        double freq {};
        freq = calculateFrequency(i, baseFrequency);

        outputFile << "Midi note number: " << i << "   =======   Frequency: " << std::fixed << std::setprecision(2) << freq << "Hz" << std::endl;
    }
}


int main() 
{
    fileOpen();
    calcerLoop();
    outputFile.close();
    return 0;
}
