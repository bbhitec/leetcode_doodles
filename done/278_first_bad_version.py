##!/usr/bin/env python
'''
    @author [mst]
    @file   278_first_bad_version.py    
    @brief  leetcode problems series
    278. First Bad Version
    You are a product manager and currently leading a team to develop a new product. Unfortunately, the latest version of your product fails the quality check. Since each version is developed based on the previous version, all the versions after a bad version are also bad.
    Suppose you have n versions [1, 2, ..., n] and you want to find out the first bad one, which causes all the following ones to be bad.
    You are given an API bool isBadVersion(version) which returns whether version is bad. Implement a function to find the first bad version. You should minimize the number of calls to the API.

    Constraints:
    1 <= bad <= n <= 231 - 1

    gains:
    -BST constraints

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# iterative binary search approach
# sub: 6%T 64%S
class Solution:
     def firstBadVersion(self, n: int) -> int:
        # consider constraint: 1 <= nums.length <= 104
        if n == 1:
            if isBadVersion(1): return 1

        lower = 1
        upper = n

        while lower < upper:
            middle = (upper + lower) // 2
            if not isBadVersion(middle):
                lower = middle + 1
            else:
                upper = middle
        return lower

# naive linear solution: just check every dataset member if a good version
class Solution9:
     def firstBadVersion(self, n: int) -> int:
        for version in range(1,n+1):
            if isBadVersion(version):
                return version
        return -1


# use bad version as a global variable
# 1 <= bad <= n <= 2^31 - 1
bad = 1

def setBad (version):
    global bad
    bad = version 


def isBadVersion(version: int) -> bool:
    global bad
    return (version >= bad)


################## DRIVER
def main():
    
    sol = Solution()

    # versions = 5    
    # setBad(4)
    # print(sol.firstBadVersion(versions))

    # versions = 1
    # setBad(1)
    # print(sol.firstBadVersion(versions))

    versions = 2126753390
    setBad(1702766719)
    print(sol.firstBadVersion(versions))
    


if __name__ == ("__main__"):
    main()
