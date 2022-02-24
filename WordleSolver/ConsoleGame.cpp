#include <iostream>
#include <map>
#include <vector>
#include <chrono>
#include <thread>
#include "defines.h"
#include "Functions.h"

using namespace std;

string generateAnswer() {

	return "oasis"; // FIXME generate answer randomly from dictionary
}

bool isValidWord(string word) {
	return true; // FIXME check that word is in the dictionary
}

void playConsoleGame() {
	string answer = generateAnswer();
	string guess = "";
	map <char, int> answer_letters;
	vector<int> result(5,0); // Result format : 0 = Not there, 1 = Wrong position, 2 = Correct
	int i, j; 
	for (i = 0;i < NUM_GUESSES;i++) {
		for (j = 0;j < WORD_SIZE; j++) {
			answer_letters[answer[j]]++; // Keep hashmap of letters that are available for scoring guesses
		}
		while (guess.size() != 5 || !isValidWord(guess)) {	// Loop until input is 5 letter word that exists in our dictionary
			cout << "Enter valid 5 letter word: " << endl;
			cin >> guess;
		}
		for (j = 0;j < WORD_SIZE;j++) {
			guess[j] = tolower(guess[j]); // Convert all words to lowercase
		}
		for (auto letter : guess) {
			cout << "\t ";
			cout << (char)toupper(letter);
		}
		cout << endl;
		for (j = 0;j < WORD_SIZE;j++) {
			cout << "\t";
			this_thread::sleep_for(500ms);
			if (answer[j] == guess[j]) {
				cout << "[O]";
				answer_letters[guess[j]]--;
				result[j] = LETTER_CORRECT;
			}
			else if (answer_letters[guess[j]]) {
				cout << "[~]";
				answer_letters[guess[j]]--;
				result[j] = LETTER_OFF;
			}
			else {
				cout << "[X]";
				result[j] = LETTER_WRONG;
			}
		}
		cout << endl;
		guess = "";

		answer_letters.clear();
	}
	cout << "You lose" << endl;
}