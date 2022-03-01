#pragma once
#include <map>
#include <vector>


// Generic Functions



// ====Console Game Functions====

// Top level function to play Console Game
void playConsoleGame();



// Official Game Functions




// Solver Functions
void assignMap(std::map <char, std::vector <std::string>> &contains); //takes in map and modifies it by assigning words in Words.txt to map
void printMap(std::map <char, std::vector <std::string>> &contains);
int randNum(int rollMax);

//Troubleshoot following line:
//I think it's because I'm calling contains and viableLetters as if I'm overwriting them, but am not within the function.  Revisit next time
//string guess(std::vector <char>, std::map <char, std::vector<std::string>>);