#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <random>
#include "Defines.h"
#include "Functions.h"
 
using namespace std;

//string solver(vector <int> result) {
//	contains[word[0]].push_back(word)
//}


void helloWorld()
{
	cout << "Hello World!" << endl;
}

void assignMap (map <char, vector <string>> &contains) {
	set <char> letters;
	string word;
	ifstream words("Words.txt");
	if (words.is_open())
	{
		while (getline(words, word))
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
	else cout << "Unable to open file" << endl;
}


void printMap(map <char, vector <string>> &contains) {
	cout << contains['a'].size() << endl;
	for (int i = 0; i < contains.size(); i++)
	{
		cout <<  endl;
		for (int j = 0; j < contains[i].size(); j++) {
			cout << contains[i][j] << endl;
		}
	}
}

void solver(vector <int> result, map <char, vector <string>>& contains) {
	cout << "Stuff's broke" << endl;
}

int randNum(int rollMax) {
	random_device dev;
	mt19937 rng(dev());
	uniform_int_distribution<mt19937::result_type> dist(0, rollMax);
	return dist(rng);
}

string guess(vector <char> & viableLetters, map <char, vector<string>> & contains) {
	string guess = "";
	char rand1 = viableLetters[randNum(viableLetters.size())];
	int rand2 = randNum(contains[rand1].size());
	guess = contains[rand1][rand2];
	return guess;
}
