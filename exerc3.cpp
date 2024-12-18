/**
 
Lab 3: exercise 3      ***/

#include <map>
#include <vector>
#include <iostream>
#include <fstream>
#include <numeric>
#include <algorithm>
using namespace std;

bool containsWord(const vector<string> list, const string word);

int main() {

    std::ifstream file("C:/Users/Hamilton/Desktop/TNG033/lab3/code/uppgift3_kort.txt");

    if (file.is_open()) {

        vector<string> theWords;
        std::string word;
        std::map<std::string, std::vector<std::string>> anagramGroups;

        while (file >> word) {

            if (theWords.size() == 0 || !containsWord(theWords, word)) {
                theWords.push_back(word);
            }

        }

        for (const auto& theWord  : theWords) {
            string subject = theWord;
            std::sort(subject.begin(), subject.end());
            anagramGroups[subject].push_back(theWord);
        }

        for (auto it = anagramGroups.begin(); it != anagramGroups.end(); it++) {
            if (it->second.size() < 2) {
                it = anagramGroups.erase(it);
                it--;
            }
        }

        for (const auto& [subject, group] : anagramGroups) {
            for (const auto& word : group) {
                cout << word << " ";
            }
            cout << " --> "<< group.size() << " Words";
            cout << endl;
        }



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
