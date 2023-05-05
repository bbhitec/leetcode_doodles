/**
    @author [mst]
    @brief  leetcode series
    1456_max_vowels_substr
	Given a string s and an integer k, return the maximum number of vowel letters in any substring of s with length k.
	Vowel letters in English are 'a', 'e', 'i', 'o', and 'u'.

    gains:


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <set>
#include <queue>
using namespace std;


////////////////// DECL_IMPL

template<typename T>
void print_queue(std::queue<T> q)
{
  while (!q.empty())
  {
    std::cout << q.front() << " ";
    q.pop();
  }
  std::cout << std::endl;
}


// initial sliding-window solution
//
// sub 9 5
class Solution1 {
public:
    int maxVowels(string s, int k) {
		set<char> vowels = {'a','e','i','o','u',};
		queue<char> substr;
		int ssize = 0;
		int countl = 0;
		int maxl = 0;

		// go throught the string 'window' like
		for (char ch : s) {
			if (ssize < k) {
				ssize ++;
			} else {
				// removing a vowel
				if (vowels.count(substr.front())) {
					countl--;
				}
				substr.pop();
			}
			// encountering a vowel
			if (vowels.count(ch)) {
				countl++;
				if (countl == k) return k;	// maximal possible count
				if (countl > maxl) maxl = countl;
			}
			substr.push(ch);

			print_queue(substr);
		}
		return maxl;
    }
};


// optimization: we dont really need a structure
//
// sub20 68
class Solution {
public:
    int maxVowels(string s, int k) {
		static set<char> vowels = {'a','e','i','o','u',};
		int n = s.size();
		int start = 0;
		int end = 0;

		int countl = 0;
		int maxl = 0;

		// go throught the string 'window' like
		while (end < n) {
			if (end-start >= k) {
				if (vowels.count(s[start])) {
					countl--;
				}
				start++;
			}
			if (vowels.count(s[end])) {
				countl++;
				if (countl > maxl) maxl = countl;
			}
			end++;
			if (countl == k) return k;	// maximal possible count
		}
		return maxl;
    }
};

////////////////// DRIVER
int main()
{
	Solution sol;
	// string s = "abciiidef";	int k = 3;
	// string s = "aeiou";	int k = 2;
	// string s = "leetcode";	int k = 3;
	string s = "ramadan";	int k = 2;
	cout << sol.maxVowels(s,k);
	return 0;
}
