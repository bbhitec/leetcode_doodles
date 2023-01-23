##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    1046_last_stone_weight
    You are given an array of integers stones where stones[i] is the weight of the ith stone.
    We are playing a game with the stones. On each turn, we choose the heaviest two stones and smash them together. Suppose the heaviest two stones have weights x and y with x <= y. The result of this smash is:
    If x == y, both stones are destroyed, and
    If x != y, the stone of weight x is destroyed, and the stone of weight y has new weight y - x.
    At the end of the game, there is at most one stone left.
    Return the weight of the last remaining stone. If there are no stones left, return 0.

    gains:
    -python stack operation
    

    @version 0.1 2023.01
'''

# sub 66,12%
class Solution:
    def ordered_insert(self, stones, val):
        if val == 1:
            stones.append(val)
            return stones
        idx = 0

        length = len(stones)
        while idx < length and val <= stones[idx]:
            idx = idx + 1

        stones.insert(idx,val)
        return stones

    def lastStoneWeight(self, stones: [int]) -> int:
        stones.sort(reverse=True)
        print (stones)

        s1 = 0
        s2 = 0
        diff = 0

        while stones:
            s1 = stones.pop(0)
            if stones:
                s2 = stones.pop(0)
            else:
                return s1

            diff = abs(s1-s2)
            if not stones: return diff
            if diff != 0:
                stones = self.ordered_insert(stones, diff)

        return 0

################## DRIVER
def main():
    sol = Solution()

    stones = [2,7,4,1,8,1]
    print (f"{stones=} res: {sol.lastStoneWeight(stones)}")

    stones = [7,6,7,6,9]
    print (f"{stones=} res: {sol.lastStoneWeight(stones)}")



if __name__ == ("__main__"):
    main()
