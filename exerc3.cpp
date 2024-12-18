/**************************
 * Lab 3: exercise 3      *
 **************************/

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
using namespace std;

bool containsWord(const vector<string> list, const string word);
map<string, vector<string>> sortingMap(const vector<string> words);

int main() {

	std::ifstream file("C:/Users/ville/Desktop/tng033/lab3/code/uppgift3_kort.txt");
	
	if (file.is_open()) {

		vector<string> theWords;
		std::string word;

		while (file >> word) {

			if (theWords.size() == 0 || !containsWord(theWords, word)) {
				theWords.push_back(word);
			}

		}

		

		//for (auto i : theWords)  cout << i << "\n";

		sortingMap(theWords);

	}

	return 0;
}

bool containsWord(const vector<string> words, const string word) {

	for (string s : words) {
		if (s == word) {
			return true;
		}
	}

	return false;
}

map<string, vector<string>> sortingMap(vector<string> words){

	map<string, vector<string>> theList;
	vector<string> sortedKeys;

	for (std::string& word : words) {
		std::sort(word.begin(), word.end());

		if (!containsWord(sortedKeys, word)) {
			sortedKeys.push_back(word);
		}
	}

	for (auto i : sortedKeys)  cout << i << "\n";

	/* for (int i = 0; i < words.size(); i++) {

		string aWord = words[i];
		sort(aWord.begin(), aWord.end());

		if (!containsWord(sortedKeys, aWord)) {
			;
		}
	} */

	
	

	return theList;
}
