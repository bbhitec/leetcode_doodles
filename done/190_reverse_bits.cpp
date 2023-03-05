/**
    @author [mst]
    @brief  leetcode problems series
    190_reverse_bits
    Reverse bits of a given 32 bits unsigned integer.

    gains:
	-basic bits operation in cpp

    @version 2023.02
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>           // usage of console prints
#include <bitset>			// [demo] usage of binary outputs

using namespace std;


////////////////// DECL_IMPL

// snipped: build a new uint 32 and fill with bits while running and shifting
//
// sub: 100t 37s
class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
		if (n == 0) return 0;

        uint32_t result = 0;
        for (int i = 0; i < 32; i++) {
            result <<= 1;
            if ((n & 1) == 1) result++;
            n >>= 1;
        }
        return result;
    }
};


////////////////// DRIVER
int main()
{
	Solution sol;

	uint32_t n = 0b00000010100101000001111010011100;

	cout << "before: 0b" << std::bitset<32>(n) << endl;
	uint32_t res = sol.reverseBits(n);
	cout << endl << "after: 0b" << std::bitset<32>(res) << endl;

	return 0;
}
