// WordleSolver.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include "defines.h"
#include "Functions.h"
using namespace std;

int main()
{
    bool quit = false;
    int mode;
    while (!quit) {
        mode = -1;
        while (mode != 1 && mode != 2) {
            cout << "Mode Select (1 for console game, 2 for official): " << endl;
            cin >> mode;
        }
        switch (mode) {
        case CONSOLE_MODE:
            PlayConsoleGame();
            break;
        case OFFICIAL_MODE: // Official game

            break;
        }
        cout << "q for quit" << endl;
        string temp;
        cin >> temp;
        quit = (temp == "q");
    }
    cout << "Thanks for playing" << endl;
    return 0;
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
