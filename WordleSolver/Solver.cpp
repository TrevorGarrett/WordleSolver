#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include "Defines.h"
#include "Functions.h"
 
using namespace std;

map <char, vector <string>> contains;

//string solver(vector <int> result) {
//	contains[word[0]].push_back(word)
//}


void helloWorld()
{
	cout << "Hello World!" << endl;
}

void assignMap () {
	string word;
	ifstream words("Words.txt");
	if (words.is_open())
	{
		while (getline(words, word))
		{
			for (int i = 0; i < 5; i++)
			{
				contains[word[i]].push_back(word);
			}
		}
		words.close();
	}
	else cout << "Unable to open file" << endl;
}


void printMap() {
	cout << contains[2].size() << endl;
	for (int i = 0; i = contains.size(); i++)
	{
		cout << '\n\n\n\n' << endl;
		for (int j = 0; j = contains[i].size(); i++) {
			cout << contains[i][j] << endl;
		}
	}
}