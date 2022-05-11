#pragma once
#include <unordered_map>
#include <set>
#include <fstream>
#include <string>
#include <iostream>
#include <random>
#include "Defines.h"

class Game {
	//std::unordered_map <char, std::vector <std::string>> contains;
	std::vector<std::string> contains;
	std::vector<char> viable_letters; // vector of allowable letters.This vector will be edited to remove letters no found in words to allow for the random guesser to pick words that adhere to any omissions made
	bool solver_mode;
	int guesses_used;
	std::string answer;
public:
	Game(std::string source_file);
	void assignMap(std::string source_file); // Initializes the internal map "contains" with dictionary of words (text file)
	void printContains(); 
	void printViableLetters();
	std::string generateGuess(); // Picks a random word using any remaining viable letters from the "contains" map
	void solverMode(); // Prompts the user if they want to enter solver mode, sets solver_mode bool
	bool getSolverMode() { return this->solver_mode; }
	int getGuessesUsed() { return this->guesses_used; }
	void incrementGuesses() { this->guesses_used++; }
	void resetGame(std::string source_file); //FIXME need to implement
	void generateAnswer(); // Generates final answer for user/solver to guess, sets "answer" member 
	void consumeResult(std::string guess, std::vector<int> result); //FIXME currently only updates viable letters for "not there" guessed letters, is there an effective way to use "wrong position" guessed letters?
	std::string getAnswer() { return this->answer; }
};



