#include <iostream>

int main()
{
    int octave = -1;
    std::string noteNames[12] = {"C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"};
    for (int i = 0; i < 128; i++)
    {
        int modulo = i % 12;
        int pianoNote = i - 20;
        std::string noteName = noteNames[modulo];

        if (i < 21)
        {
            std::cout << "note number : " << i << std::endl;
            std::cout << "piano note  : not valid" << std::endl;
            std::cout << "modulo      : " << modulo << std::endl;
            std::cout << "note name   : not valid" << std::endl;
            std::cout << "octave      : not valid" << std::endl;
            std::cout << "note w/ oct : not valid" << std::endl << std::endl; 
        }
        else if (pianoNote > 88)
        {
            std::cout << "note number : " << i << std::endl;
            std::cout << "piano note  : not valid" << std::endl;
            std::cout << "modulo      : " << modulo << std::endl;
            std::cout << "note name   : " << noteName << std::endl;
            std::cout << "octave      : " << octave << std::endl;
            std::cout << "note w/ oct : " << noteName << octave << std::endl << std::endl;  
        }
        else
        {
            std::cout << "note number : " << i << std::endl;
            std::cout << "piano note  : " << pianoNote << std::endl;
            std::cout << "modulo      : " << modulo << std::endl;
            std::cout << "note name   : " << noteName << std::endl;
            std::cout << "octave      : " << octave << std::endl;
            std::cout << "note w/ oct : " << noteName << octave << std::endl << std::endl;
        }


        if (modulo == 11)
        {
            octave++;
        }
    }

    return 0;
}