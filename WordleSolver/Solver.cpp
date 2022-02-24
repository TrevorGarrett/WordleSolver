#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
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
	set <char> letters;
	string word;
	ifstream words("Words.txt");
	if (words.is_open())
	{
		while (getline(words, word))
		{
			for (int i = 0; i < 5; i++)
			{
				if (letters.count(word[i])) 
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


void printMap() {
	cout << contains['a'].size() << endl;
	for (int i = 0; i < contains.size(); i++)
	{
		cout <<  endl;
		for (int j = 0; j < contains[i].size(); j++) {
			cout << contains[i][j] << endl;
		}
	}
}