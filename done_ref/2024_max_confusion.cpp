/**
    @author [mst]
    @brief  leetcode series
    2024_max_confusion
    A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).
    You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:
    Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').
    Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

    gains:
    -sliding window with modifications counter
    -[wip] polish the window borders logic

    @version 0.1 2023.07
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL

// snipped - walkcc reference
// sliding window approach
//
// sub 88 58
class Solution {
public:
  int maxConsecutiveAnswers(string answerKey, int k) {
    int ans = 0;
    int maxCount = 0;
    vector<int> count(2); // counting True and False in the window
    int sz = answerKey.length();

    // slide the window while arbitrating T/F counts
    for (int l = 0, r = 0; r < sz; ++r) {
      bool curr = answerKey[r] == 'T';
      count[curr]++;
      maxCount = max(maxCount, count[curr]);
      // advance left side
      while (maxCount + k < r - l + 1) {
        bool curr = answerKey[l++] == 'T';
        count[curr]--;
      }
      ans = max(ans, r - l + 1);  // the answer is the longest window achieved
    }
    return ans;
  }
};

////////////////// DRIVER
int main()
{
    Solution s;

    // string answerKey = "TTFF";
    string answerKey = "TTFTTFTT";
    // string answerKey = "TFFT";
    int k = 1;

    int res = s.maxConsecutiveAnswers(answerKey, k);
    cout << res;


    return 0;
}