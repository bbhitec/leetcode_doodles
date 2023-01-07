##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    118_pascals_triangle
    Given an integer numRows, return the first numRows of Pascal's triangle.
    In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:

    Gains:
    -python list traversal and loop precision

    features, changelog:
    -2023.01: -submission
'''

# go each line adding the relevant members
# hints from: https://youtu.be/nPVEaB3AjUM
#
# sub: 90%T 17%S 
class Solution:
    def generate(self, numRows: int) -> [[int]]:
        # the constraint allows us the initialization
        res =[[1]]

        for row in range(numRows-1):
            last = res[-1]
            # pseudo-pad the last row
            tmp = [0] + last + [0]            
            built = []
            for member in range(len(last) + 1):
                built.append(tmp[member] + tmp[member+1])
            res.append(built)

            # # check-up
            # print (f"{built} ")

        return res

        

################## DRIVER
def main():
    
    sol = Solution()

    n = 7
    print(f"{sol.generate(n)=}")


if __name__ == ("__main__"):
    main()
