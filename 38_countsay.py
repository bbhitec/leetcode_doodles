''' 
[mst] 38_countsay.py
leetcode problems series

38. Count and Say Easy
The count-and-say sequence is a sequence of digit strings defined by the recursive formula:
countAndSay(1) = "1"
countAndSay(n) is the way you would "say" the digit string from countAndSay(n-1), which is then converted into a different digit string.
To determine how you "say" a digit string, split it into the minimal number of groups so that each group is a contiguous section all
of the same character. Then for each group, say the number of characters, then say the character. To convert the saying into a digit
string, replace the counts with a number and concatenate every saying.

Example 2:
Input: n = 4
Output: "1211"
Explanation:
countAndSay(1) = "1"
countAndSay(2) = say "1" = one 1 = "11"
countAndSay(3) = say "11" = two 1's = "21"
countAndSay(4) = say "21" = one 2 + one 1 = "12" + "11" = "1211"
1 <= n <= 30


log:
- 2022.04 [wip] snipped a solution, not reviewed
- initial hash-based solution (I think I've copied it from somewhere)

'''


'''
class Solution0(object):
    # [wip] my initial solution
    def say(self, sequence):
        s = str(sequence)
        res = []
        
        count = 0
        for i in range(len(s)):
            char = s[i]
            if (i > 1) and s[i-1] == char:
            str = count + 1 # [here]
            
            
                continue
            res.append(chr(prev_s.count(char)))
            res.append(char)
        print (res)
    
    def countAndSay(self, n):
        """
        :type n: int
        :rtype: str
        """
        if n==1:
            return '1'
        
        prev = self.countAndSay(n - 1)
        res = self.say(prev)
        
        return res
'''

class Solution:
    '''
    snipped from discussion section
    '''
    def countAndSay(self, n: int) -> str:
        if n == 1:
            return "1"
        
        return self.say(self.countAndSay(n-1))        
    
    def say(self, s: str) -> str:
        cur, count = s[0], 1
        res = []
        for i in range(1, len(s)):
            if s[i] == cur:
                count += 1
            else:
                res.append(str(count))
                res.append(cur)
                count = 1
                cur = s[i]
        res.append(str(count))
        res.append(cur)
        return ''.join(res)
        

# driver
def main():
    print ("[mst] leetcode 38. Count and Say")
 
    s = Solution()
    n = 4
    print(s.countAndSay(n))

# [mst][demo] this is a check for running via command line
if __name__ == ("__main__"):
    main()
    
        