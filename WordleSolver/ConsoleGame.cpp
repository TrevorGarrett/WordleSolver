#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>
#include "defines.h"
#include "Functions.h"
#include "Game.h"

bool isValidWord(std::string word) {
	return true; // FIXME check that word is in the dictionary
}

void playConsoleGame(Game* game) { //FIXME need to remove letters from viableLetters, should this happen in solver?
	game->generateAnswer();
	std::string answer = game->getAnswer();
	std::string guess;
	std::unordered_map <char, int> answer_letters;
	std::vector<int> result(5,0); // Result format : 0 = Not there, 1 = Wrong position, 2 = Correct
	game->solverMode();
	int i; 
	while (game->getGuessesUsed() < NUM_GUESSES && guess != answer) {
		guess = "";
		answer_letters.clear();
		for (i = 0;i < WORD_SIZE; i++) {
			answer_letters[answer[i]]++; // Keep hashmap of letters that are available for scoring guesses, keeping number of occurences in hashmap allows for multiple "wrong positions" for the same letter 
		}
		if (game->getSolverMode()) {
			guess = game->generateGuess();
		}
		else {
			while (guess.size() != 5 || !isValidWord(guess)) {	// Loop until input is 5 letter word that exists in our dictionary
				std::cout << "Enter valid 5 letter word: " << std::endl;
				std::cin >> guess;
			}
		}
		for (i = 0;i < WORD_SIZE;i++) {
			guess[i] = tolower(guess[i]); // Convert all words to lowercase
		}
		for (auto letter : guess) {
			std::cout << "\t ";
			std::cout << (char)toupper(letter);
		}
		std::cout << std::endl;
		for (i = 0;i < WORD_SIZE;i++) { // First check for "Correct" guessed letters to avoid "wrong position" designation for duplicate letters and only the second is correct Ex) guess = "booth" answer = "trope", first "o" in guess should be X instead of ~
			if (answer[i] == guess[i]) {
				answer_letters[guess[i]]--;
				result[i] = LETTER_CORRECT;
			}
		}
		for (i = 0;i < WORD_SIZE;i++) {
			std::cout << "\t";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			if (answer[i] == guess[i]) {
				std::cout << "[O]";
			}
			else if (answer_letters[guess[i]]) {
				std::cout << "[~]";
				answer_letters[guess[i]]--;
				result[i] = LETTER_OFF;
			}
			else {
				std::cout << "[X]";
				result[i] = LETTER_WRONG;
			}
		}
		std::cout << std::endl;
		//solver(guess, result, contains);
		game->incrementGuesses();
		game->consumeResult(guess, result);
#if DEBUG_MODE == 1
		game->printViableLetters();
#endif
	}
	if (guess == answer) {
		std::cout << "You win" << std::endl;
	}
	else {
		std::cout << "You lose" << std::endl;
	}
}