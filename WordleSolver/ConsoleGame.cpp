#include <iostream>
#include <unordered_map>
#include <vector>
#include <chrono>
#include <thread>
#include "defines.h"
#include "Functions.h"

std::string generateAnswer(std::unordered_map<char, std::vector<std::string>> &contains) {
	std::string answer;
	auto iterator = contains.begin();
	std::advance(iterator, rand()%contains.size());
	int bucket_size = iterator->second.size();
	answer = iterator->second[rand() % bucket_size];
#if DEBUG_MODE == 1
	std::cout << "==== ANSWER ====" << std::endl << answer << std::endl;
#endif
	return answer;
}

bool isValidWord(std::string word) {
	return true; // FIXME check that word is in the dictionary
}

void playConsoleGame(std::vector<char>& viableLetters, std::unordered_map<char, std::vector<std::string>> &contains) { //FIXME need to remove letters from viableLetters, should this happen in solver?
	std::string answer = generateAnswer(contains);
	std::string guess = "";
	std::unordered_map <char, int> answer_letters;
	std::vector<int> result(5,0); // Result format : 0 = Not there, 1 = Wrong position, 2 = Correct
	bool solver_mode = solverMode();
	int i, j; 
	for (i = 0;i < NUM_GUESSES;i++) {
		for (j = 0;j < WORD_SIZE; j++) {
			answer_letters[answer[j]]++; // Keep hashmap of letters that are available for scoring guesses
		}
		if (solver_mode) {
			guess = generateGuess(viableLetters, contains);
		}
		else {
			while (guess.size() != 5 || !isValidWord(guess)) {	// Loop until input is 5 letter word that exists in our dictionary
				std::cout << "Enter valid 5 letter word: " << std::endl;
				std::cin >> guess;
			}
		}
		for (j = 0;j < WORD_SIZE;j++) {
			guess[j] = tolower(guess[j]); // Convert all words to lowercase
		}
		for (auto letter : guess) {
			std::cout << "\t ";
			std::cout << (char)toupper(letter);
		}
		std::cout << std::endl;
		for (j = 0;j < WORD_SIZE;j++) {
			std::cout << "\t";
			std::this_thread::sleep_for(std::chrono::milliseconds(500));
			if (answer[j] == guess[j]) {
				std::cout << "[O]";
				answer_letters[guess[j]]--;
				result[j] = LETTER_CORRECT;
			}
			else if (answer_letters[guess[j]]) {
				std::cout << "[~]";
				answer_letters[guess[j]]--;
				result[j] = LETTER_OFF;
			}
			else {
				std::cout << "[X]";
				result[j] = LETTER_WRONG;
			}
		}
		std::cout << std::endl;
		//solver(guess, result, contains);
		guess = "";
		answer_letters.clear();
	}
	std::cout << "You lose" << std::endl;
}