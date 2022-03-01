#pragma once
#include <unordered_map>
#include <vector>


// ====Generic Functions====



// ====Console Game Functions====
void playConsoleGame(std::vector<char>& viableLetters, std::unordered_map <char, std::vector<std::string>> &contains); // Top level function to play Console Game, map will be passed to solver to be modified if in solver mode.



// ====Official Game Functions====




// ====Solver Functions====
void assignMap(std::unordered_map <char, std::vector <std::string>> &contains); //takes in map and modifies it by assigning words in Words.txt to map
void printMap(std::unordered_map <char, std::vector <std::string>> & contains);
int randNum(int rollMax);
std::string generateGuess(std::vector <char> viableLetters, std::unordered_map <char, std::vector<std::string>>); // Returns random guess given an array of possible letters and a remaining valid words
bool solverMode(); // Asks if user wants to use solver mode, returns true for solver mode, false otherwise
//void solver(std::string guess, std::vector <int> result, std::unordered_map <char, std::vector <std::string>>& contains);
void assignMap(std::unordered_map <char, std::vector <std::string>> &contains); //takes in map and modifies it by assigning words in Words.txt to map
void printMap(std::unordered_map <char, std::vector <std::string>> &contains);