#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>
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

void Solver(std::string guess, std::vector <int> result, std::unordered_map <char, std::vector <std::string>>& contains) {
	std::cout << "Stuff's broke";
}

