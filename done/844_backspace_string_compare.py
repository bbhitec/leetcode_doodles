##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    844_backspace_string_compare
    Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.
    Note that after backspacing an empty text, the text will continue empty.

    Gains:
    -python string manipulations

    features, changelog:
    -2023.01: -submission
'''

# simply clean each string and compare them
#
# sub: 49%T 98%S
class Solution:
    def backspaceCompare(self, s: str, t: str) -> bool:
        s_f = ""
        t_f = ""

        for i in range(len(s)):
            if s[i] == "#":
                s_f = s_f[:-1]
            else:
                s_f = s_f + s[i]

        for i in range(len(t)):
            if t[i] == "#":
                t_f = t_f[:-1]
            else:
                t_f = t_f + t[i]

        # print(f"{s_f=} {t_f=}")

        return s_f == t_f


################## DRIVER
def main():

    sol = Solution()

    # s = "ab#c"
    # t = "ad#c"

    # s = "ab##"
    # t = "c#d#"

    s = "a#c"
    t = "b"

    print(f"{s=} {t=}")
    print(f"{sol.backspaceCompare(s, t)=}")


if __name__ == ("__main__"):
    main()
