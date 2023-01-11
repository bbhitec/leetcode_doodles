##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    387_first_unique 

    gains:
    -python dict basics

    features, changelog:
    -2023.01: -submission

    @version 0.1 2023.01
'''

# build a dict of occurances and save nullify any repeated characters
# then, return the first un-nullified one
#
# sub:88%T 57%S
class Solution:
    def firstUniqChar(self, s: str) -> int:
        numset={}
        for i,c in enumerate(s):
            if c in numset:
                numset[c] = -1
            else:
                numset[c] = i

        for x in numset:
            if numset[x] != -1:
                return numset[x]

        return -1
            


################## DRIVER
def main():
    
    sol = Solution()
    s = "leetcode"
    #s = "loveleetcode"
    print(f"{s=} result: {sol.firstUniqChar(s)=}")



if __name__ == ("__main__"):
    main()
