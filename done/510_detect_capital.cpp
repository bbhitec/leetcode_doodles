/**
    @author [mst]
    @file   510_detect_capital
    @brief  title or quick description
    
	We define the usage of capitals in a word to be right when one of the following cases holds:
	All letters in this word are capitals, like "USA".
	All letters in this word are not capitals, like "leetcode".
	Only the first letter in this word is capital, like "Google".
	Given a string word, return true if the usage of capitals in it is right.

    Gains:
	-conditionals basics

    @version 0.1 2023.01
*/ 


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <string>
using namespace std;


////////////////// DECL_IMPL

// naive: go through the string once for every sentence type
//
// sub: 47%T 70%S
class Solution {
public:
    bool isLower(string word) {
        for (char c : word) {
            if (!(('a' <= c ) && ('z' >= c))) return false;
        }
        //cout << "isLower!" << endl;
        return true;
    }

     bool isCapital(string word) {
        for (char c : word) {
            if (!(('A' <= c ) && ('Z' >= c))) return false;
        }
        //cout << "isCapital!" << endl;
        return true;
    }

    bool isSentence(string word) {
        char first = word[0];
        if (('A' <= first ) && ('Z' >= first)) {
            int i = 1;

            while (word[i] != '\0') {
                if (!(('a' <= word[i] ) && ('z' >= word[i]))) return false;
                i++;
            }
            //cout << "isSentence!" << endl;
            return true;
        }
        else return false;

    }


    bool detectCapitalUse(string word) {
        if (word.size() == 1) return true;
        
        bool capital = isCapital(word);
        bool lower = isLower(word);
        bool sentence = isSentence(word);

        if (capital || lower || sentence) return true;
        return false;
    }
};

////////////////// DRIVER
int main()
{
	Solution sol;

    string word = "USa";
	cout << "result: " << sol.detectCapitalUse(word);

	cin.get(); // pseudo-pause the console
	return 0;
}
