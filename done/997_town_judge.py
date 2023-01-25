##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    997_town_judge
    In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
    If the town judge exists, then:
    The town judge trusts nobody.
    Everybody (except for the town judge) trusts the town judge.
    There is exactly one person that satisfies properties 1 and 2.
    You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
    Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.

    gains:
    -simple graph algorithmic solution


    @version 0.1 2023.01
'''

# sub 32,25%
class Solution:
    def findJudge(self, n: int, trust: [[int]]) -> int:
        if n==1:
            return 1

        j = -1

        weights = [0 for i in range(n+1)]

        for row in trust:
            outbound = row[0]
            inbound = row[1]
            weights[outbound] = weights[outbound] - 1
            weights[inbound] = weights[inbound] + 1

        for i in range(1,n+1):
            if weights[i] == n-1:
                j = i

        return j

################## DRIVER
def main():
    sol = Solution()

    n, trust = 2,[[1,2]]
    print (f"{trust=} {n=} res: {sol.findJudge(n, trust)}")

    n, trust = 4,[[1,3],[1,4],[2,3],[2,4],[4,3]]
    print (f"{trust=} {n=} res: {sol.findJudge(n, trust)}")



if __name__ == ("__main__"):
    main()
