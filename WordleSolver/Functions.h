#pragma once
#include <unordered_map>
#include <vector>


// Generic Functions



// ====Console Game Functions====

// Top level function to play Console Game, map will be passed to solver to be modified if in solver mode.
void playConsoleGame(std::unordered_map <char, std::vector<std::string>> &contains); 



// Official Game Functions




// Solver Functions
void Solver(std::string guess, std::vector <int> result, std::unordered_map <char, std::vector <std::string>>& contains);
void assignMap(std::unordered_map <char, std::vector <std::string>> &contains); //takes in map and modifies it by assigning words in Words.txt to map
void printMap(std::unordered_map <char, std::vector <std::string>> &contains);