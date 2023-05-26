/**
    @author [mst]
    @brief  leetcode series
    338_counting_bits
    Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

    gains:
    -cpp bit manipulation basics


    @version 2023.05
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <bit>          // for popcount (not very portable)
#include <bitset>
using namespace std;



////////////////// DECL_IMPL


// snipped:
// using the fact that even numbers have the same amount of bits as their halves
// and odd numbers have double + 1 bits as their half
//
// sub: 28 52
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> t(n + 1);

        t[0] = 0;
        for (int i = 1; i <= n; ++i)  {
            t[i] = t[i / 2] + i % 2;
        }

        return t;
    }
};

// sub 28 35
class Solution2 {
public:
    vector<int> countBits(int n) {
        vector<int> res = {};

        for (int i = 0; i < n; i++) {
            int count = bitset<32>(i).count();
            res.push_back(count);
        }

        return res;
    }
};

// this uses cpp build in function 'popcount' to coun integer bits
class Solution1 {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while (n != 0) {
            if ((n & 1) == 1) count = count +1;
            n = n >> 1;
        }
        return count;
    }

    vector<int> countBits(int n) {
        vector<int> res = {};

        for (int i = 0; i < n; i++) {
            res.push_back(__popcount(i));
        }

        return res;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    int n=5;
    vector<int> res = s.countBits(n);
    for (auto &v : res) {
        cout << v << " ";
    }

    return 0;
}