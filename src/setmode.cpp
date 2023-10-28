#include <iostream>

int setMode()
{
    char mode{};
    std::cout << "\033[1;34mPlease select a mode: \033[0m";
    std::cout << "'g': Generate a file" << std::endl;
    std::cout << "'w': Write out a file" << std::endl;

    std::cin >> mode;
    int returnMode;
    switch(mode)
    {
        case 'g':
            returnMode = 1;

        case 'w':
            returnMode = 2;
    }

    return returnMode;
}