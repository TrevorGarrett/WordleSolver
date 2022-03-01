#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <random>
#include "Defines.h"
#include "Functions.h"

//string solver(vector <int> result) {
//	contains[word[0]].push_back(word)
//}


void helloWorld()
{
	std::cout << "Hello World!" << std::endl;
}

void assignMap (std::unordered_map <char, std::vector <std::string>> &contains) {
	std::set <char> letters;
	std::string word;
	std::ifstream words("Words.txt");
	if (words.is_open())
	{
		while (std::getline(words, word))
		{
			for (int i = 0; i < 5; i++)
			{
				if (!letters.count(word[i])) 
				{
					letters.insert(word[i]);
					contains[word[i]].push_back(word);
				}
			}
			letters.clear();
		}
		words.close();
	}
	else std::cout << "Unable to open file" << std::endl;
}


void printMap(std::unordered_map <char, std::vector <std::string>> &contains) {
	std::cout << contains['a'].size() << std::endl;
	for (auto bucket : contains)
	{
		std::cout << std::endl;
		for (auto word : bucket.second) {
			std::cout << word << std::endl;
		}
	}
}

bool solverMode() {
	std::cout << "Run in solver mode?" << std::endl;
	std::string answer = "";
	while (answer != "yes" && answer != "no")
	{
		std::cin >> answer;
		int i;
		for (i = 0; i < answer.length(); i++) {
			answer[i] = tolower(answer[i]);
		}
	}
	if (answer == "yes") {
		return true;
	}
	return false;
}

void solver(std::vector <int> result, std::unordered_map <char, std::vector <std::string>>& contains) {
	std::cout << "Stuff's broke" << std::endl;
}

int randNum(int rollMax) {
	std::random_device dev;
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> dist(0, rollMax);
	return dist(rng);
}

std::string guess(std::vector <char> viableLetters, std::unordered_map <char, std::vector< std::string>> contains) {
	std::string guess = "";
	char rand1 = viableLetters[randNum(viableLetters.size()-1)];
	int rand2 = randNum(contains[rand1].size());
	guess = contains[rand1][rand2];
	return guess;
}
