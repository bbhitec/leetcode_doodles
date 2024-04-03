#
# [mst] 205_isomorphic_strings.cpp
# Given two strings s and t, determine if they are isomorphic.
# Two strings s and t are isomorphic if the characters in s can be replaced to get t.
# All occurrences of a character must be replaced with another character while
# preserving the order of characters. No two characters may map to the same character, but a character may map to itself.
#
# Gains:
# -py map
# -rd fin
#


# build an indexes map for each char in each string and compare the maps
# assisted
#
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        return [*map(s.index, s)] == [*map(t.index, t)]




################## DRIVER
def main():
    sol = Solution()
    s = "egg"
    t = "add"
    print(sol.isIsomorphic(s,t))


if __name__ == ("__main__"):
    main()

