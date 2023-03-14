/**
    @author [mst]
    @brief  leetcode series
    443_string_compression
	Given an array of characters chars, compress it using the following algorithm:
	Begin with an empty string s. For each group of consecutive repeating characters in chars:
	If the group's length is 1, append the character to s.
	Otherwise, append the character followed by the group's length.
	The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
	After you are done modifying the input array, return the new length of the array.
	You must write an algorithm that uses only constant extra space.

	gains:
    -string traversal in cpp


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// single string traversal
//
// sub: 28s 29t
class Solution
{
public:
	int compress(vector<char> &chars)
	{
		int sz = chars.size();
		int ans = 0;

		for (int i = 0; i < sz;)
		{
			const char letter = chars[i];
			int count = 0;
			while (i < sz && chars[i] == letter)
			{
				++count;
				++i;
			}
			chars[ans++] = letter;
			if (count > 1)
				for (const char c : to_string(count))
					chars[ans++] = c;
		}

		return ans;
	}
};

////////////////// DRIVER
int main()
{
	Solution s;
	vector<char> ch = {'a','a','b','b','c','c','c'};

	for (const auto& n : ch) cout << n << ", ";
	cout << endl;
	cout << "res: " << s.compress(ch);
	return 0;
}
