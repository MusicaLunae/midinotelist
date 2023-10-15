#include <iostream>
#include <iomanip>
// #include <json/json.h>
#include <fstream>
#include <cmath>

double baseFreq = 440.00;
std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
std::ofstream outputFile;

int gatherInput()
{
    int midiNote{};
    std::cout << "Please enter the midi note number you want to calculate with: ";
    std::cin >> midiNote;
    std::cout << "\nyou entered note number: " << midiNote;
    std::cout << "\n\n";

    return midiNote;
}

double powCalc(int midiNoteNum)
{
    double exp{};
    double expStep1{};
    double expStep2{};
    double power{};

    expStep1 = midiNoteNum - 69;
    std::cout << "expStep1: " << expStep1 << std::endl;

    expStep2 = expStep1 / 12;
    std::cout << "expStep2: " << expStep2 << std::endl;

    power = pow(2, expStep2);
    std::cout << "power:    " << power << std::endl;

    return power;
}

double frequencyCalc(double freq, int midiNoteNum)
{
    double outputFreq{};
    // double exponent = ((midiNoteNum - 69) / 12);
    // outputFreq = freq * pow(2, exponent);

    double power = powCalc(midiNoteNum);
    outputFreq = freq * power;


    std::cout << "input baseFreq:    " << baseFreq << "Hz" << std::endl;
    std::cout << "input midiNoteNum: " << midiNoteNum << std::endl;
    std::cout << "output frequency:  " << outputFreq << "Hz" << std::endl;
    return outputFreq;

}

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
    // int userInput = gatherInput();
    // double calculatedFrequency = frequencyCalc(baseFreq, userInput);
    
    fileOpen();
    calcerLoop();
    outputFile.close();
    return 0;
}