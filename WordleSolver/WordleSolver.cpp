// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>
#include "defines.h"
#include "Functions.h"

int main()
{
    std::unordered_map <char, std::vector <std::string>> contains;
    bool quit = false;
    int mode;
    std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; // List of letters to initiate vector of allowable letters
    std::vector <char> viableLetters; // vector of allowable letters.  This vector will be edited to remove letters no found in words to allow for the random guesser to pick words that adhere to any omissions made
    for (int i = 0; i < alphabet.length(); i++) {
        viableLetters.push_back(alphabet[i]);
    }
    while (!quit) {
        mode = -1;
        while (mode != 1 && mode != 2) {
            std::cout << "Mode Select (1 for console game, 2 for official): " << std::endl;
            std::cin >> mode;
        }
        switch (mode) {
        case CONSOLE_MODE:
            assignMap(contains);
            std::cout << guess(viableLetters, contains) << std::endl;
            #if DEBUG_MODE == 1
               printMap(contains);
            #endif // DEBUG_MODE 
            playConsoleGame(contains);
            break;
        case OFFICIAL_MODE: // Official game

            break;
        }
        std::cout << "q for quit" << std::endl;
        std::string temp;
        std::cin >> temp;
        quit = (temp == "q");
    }
    std::cout << "Thanks for playing" << std::endl;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
