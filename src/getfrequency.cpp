#include <iostream>

double getFrequency()
{
    double freq{};
    std::cout << "\033[1;32mPlease enter a frequency to use: ";
    std::cin >> freq;
    return freq;
}