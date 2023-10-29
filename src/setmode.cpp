#include <iostream>
#include <string>

int setMode()
{
    char mode{};
    std::cout << "\033[1;34mPlease select a mode: \033[0m" << std::endl;
    std::cout << "\033[1m'g': Generate a file\033[0m" << std::endl;
    std::cout << "\033[1m'w': Write out a file\033[0m" << std::endl;
    std::cout << "\033[1m'x': Exit the program\033[0m" << std::endl;

    std::cin >> mode;
    int returnMode;
    
    const std::string validModes = "gwx";
    for (int i = 0; i < validModes.length(); i++)
    {
        if (validModes[i] == mode)
        {
            switch(mode)
            {
                case 'g':
                    returnMode = 1;
                    break;

                case 'w':
                    returnMode = 2;
                    break;

                case 'x':
                    returnMode = 3;
                    break;
            }
            break;
        }
        else
        {
            returnMode = -1;
            continue;
        }
    }
    return returnMode;
}

void wrongInput()
{
    std::cout << "\033[1;31mInvalid input.\033[0m" << std::endl;
}