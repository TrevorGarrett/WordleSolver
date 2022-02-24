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