#include "Game.h"

Game::Game(std::string source_file) {
	this->resetGame(source_file);
}

void Game::resetGame(std::string source_file) {
	this->guesses_used = 0;
	std::string alphabet = "abcdefghijklmnopqrstuvwxyz"; // List of letters to initiate vector of allowable letters
	for (size_t i = 0; i < alphabet.length(); i++) {
		this->viable_letters.push_back(alphabet[i]);
	}
	assignMap(source_file);
}


void Game::assignMap(std::string source_file) { // Vector implementation of "contains"
	std::string word;
	std::ifstream words(source_file);
	this->contains.clear();
	if (words.is_open())
	{
		while (std::getline(words, word))
		{
			this->contains.push_back(word);
		}
		words.close();
	}
	else std::cout << "Unable to open file" << std::endl;
}

/* COMMENTING OUT MAP IMPLEMENTATION OF "contains"
void Game::assignMap(std::string source_file) {
	std::set <char> letters;
	std::string word;
	std::ifstream words(source_file);
	this->contains.clear();
	if (words.is_open())
	{
		while (std::getline(words, word))
		{
			for (int i = 0; i < 5; i++)
			{
				if (!letters.count(word[i]))
				{
					letters.insert(word[i]);
					this->contains[word[i]].push_back(word);
				}
			}
			letters.clear();
		}
		words.close();
	}
	else std::cout << "Unable to open file" << std::endl;
}
*/

void Game::printContains() { // Vector implementation
	std::cout << this->contains['a'].size() << std::endl;
	for (auto word : this->contains)
	{
		std::cout << word << std::endl;
	}
}

/* MAP IMPLEMENTATION
void Game::printContains() {
	std::cout << this->contains['a'].size() << std::endl;
	for (auto bucket : this->contains)
	{
		std::cout << std::endl;
		for (auto word : bucket.second) {
			std::cout << word << std::endl;
		}
	}
}
*/

void Game::printViableLetters() {
	for (auto letter : this->viable_letters) {
		std::cout << letter;
	}
	std::cout << std::endl;
}

std::string Game::generateGuess() {
	return contains[rand() % contains.size()];
}

/* Map implementation
std::string Game::generateGuess() {
	std::string guess = "";
	char rand1 = this->viable_letters[rand() % this->viable_letters.size()];
	int rand2 = rand() % this->contains[rand1].size();
	guess = contains[rand1][rand2];
	return guess;
}
*/

void Game::solverMode() {
	std::string answer = "";
	while (answer != "y" && answer != "n")
	{
		std::cout << "Run in solver mode? y/n" << std::endl;
		std::cin >> answer;
		for (size_t i = 0; i < answer.length(); i++) {
			answer[i] = tolower(answer[i]);
		}
	}
	if (answer == "y") {
		this->solver_mode = true;
	}
	else {
		this->solver_mode = false;
	}
}

void Game::generateAnswer() { // Vector implementation
	std::string rand_answer = this->contains[rand() % contains.size()];
#if DEBUG_MODE == 1
	std::cout << "==== ANSWER BEGIN ====" << std::endl << rand_answer << "\n==== ANSWER END ====" << std::endl;
#endif
	this->answer = rand_answer;
}

/* Map implementation
void Game::generateAnswer() {
	std::string rand_answer;
	auto iterator = this->contains.begin();
	std::advance(iterator, rand() % this->contains.size());
	int bucket_size = iterator->second.size();
	rand_answer = iterator->second[rand() % bucket_size];
#if DEBUG_MODE == 1
	std::cout << "==== ANSWER BEGIN ====" << std::endl << rand_answer << "\n==== ANSWER END ===="  << std::endl;
#endif
	this->answer = rand_answer;
}
*/

void Game::consumeResult(std::string guess, std::vector<int> result) { // Vector implementation
	int i, j;
	for (i = 0;i < WORD_SIZE-1;i++) {
		for (j = i + 1;j < WORD_SIZE;j++) {
			if (guess[i] == guess[j] && (result[i] + result[j] > 0)) {
				if (result[i] == LETTER_WRONG) {
					result[i] = LETTER_OFF;
				}
				else if (result[j] == LETTER_WRONG) { result[j] = LETTER_OFF; }
			}
		}
	}
	for (i = 0;i < WORD_SIZE;i++) {
		auto it = std::find(this->viable_letters.begin(), this->viable_letters.end(), guess[i]);
		if (it != this->viable_letters.end() && result[i] == LETTER_WRONG)
			this->viable_letters.erase(it);
		for (auto c_it = this->contains.end() - 1; c_it != this->contains.begin()-1; c_it--) {
			std::string word = *c_it;
			for (j = 0;j < WORD_SIZE;j++) {
				if (word[j] != guess[j] && result[j] == LETTER_CORRECT) {
					this->contains.erase(c_it);
					break;
				}
				if (word[j] == guess[i] && result[i] == LETTER_WRONG) {
					this->contains.erase(c_it);
					break;
				}
				if (word[j] == guess[j] && result[j] == LETTER_OFF) {
					this->contains.erase(c_it);
					break;
				}
			}
		}
	}
#if DEBUG_MODE == 1 
	std::cout << "valid words left: " << contains.size() << std::endl;
#endif
}