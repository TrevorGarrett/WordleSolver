// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include <time.h>
#include "defines.h"
#include "Functions.h"
#include "Game.h"

int main()
{
    unsigned int seed = (unsigned int)time(NULL);
    srand(seed); // Set random seed based on system time
#if DEBUG_MODE == 1
    std::cout << "Seed is: " << seed << std::endl;
#endif
    Game* game = new Game("Words.txt");
    bool quit = false;
    int mode;
    while (!quit) {
        mode = -1;
        while (mode != 1 && mode != 2) {
            std::cout << "Mode Select (1 for console game, 2 for official): " << std::endl;
            std::cin >> mode;
        }
        switch (mode) {
        case CONSOLE_MODE:
            #if DEBUG_MODE == 1
                std::cout << game->generateGuess() << std::endl;   
            #endif
            #if DEBUG_MAP == 1
               game->printContains();
            #endif // DEBUG_MODE 
            playConsoleGame(game);
            break;
        case OFFICIAL_MODE: // Official game

            break;
        }
        std::cout << "q for quit" << std::endl;
        std::string temp;
        std::cin >> temp;
        quit = (temp == "q");
        if (!quit) {
            game->resetGame("Words.txt");
        }
    }
    std::cout << "Thanks for playing" << std::endl;
}