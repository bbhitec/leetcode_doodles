'''
[mst] fizzbuzz1.py
simple fizzbuzz in python3

fizzbuzz demonstrates a simple conditional flow
and can use dictionaries\hashtables optimization

log:
-2021.12: -initial draft
-2021.12: adjusted for leetcode question 412:
   Input: n = 15
   Output: ["1","2","Fizz","4","Buzz","Fizz","7","8","Fizz","Buzz","11","Fizz","13","14","FizzBuzz"]
   1 <= n <= 104
-2021.12.12: improved with a dictionary for cleaner multiple mappings

@author: mst
'''

class Solution (object):
    """
    [demo] shows the way to encapsulate the main logic in OOP manner, as a method
    """

    def fizzBuzz(self,n):
        """
        :type n: int
        :rtype: List[str]
        """
        res = []
        for i in range (1 , n+1):
            if (( i % 3 == 0) and (i % 5 == 0)): # check if divided by both first
                res.append("FizzBuzz")
            elif ( i % 3 == 0):
                res.append("Fizz")
            elif ( i % 5 == 0):
                res.append("Buzz")
            else:
                res.append(str(i))
        return (res)


class Solution2 (object):
    """
    what if we had to pront Puzz for all 7 divisibles? The naive version would
    have tonns of conditions. Therefore, we have the classificatioin approach:
    for each divisor, we add a key to a hash map
    """
    def fizzBuzz(self,n):
        res = []

        # map all replacement strings
        fizz_buzzes = {3 : "Fizz", 5 : "Buzz", 7:"Puzz"}

        for i in range (1 , n+1):

            #reset the result string for each num
            res_str = ''

            # if 'i' is divisible by 'key', replace with mapped string
            for key in fizz_buzzes:                
                if (i % key == 0):
                    res_str += fizz_buzzes[key]

            # check if answer string is empty (no replacements done)
            if not (res_str):
                res_str = str(i)
            res.append(res_str)

        return (res)


################## DRIVER
def main ():
    print ("[mst] fizzbuzz1 (leetcode 412)")

    sol1 = Solution()
    print(sol1.fizzBuzz(15))

    # here, also replace 7 divisible by 'puzz'
    sol2 = Solution2()
    print(sol2.fizzBuzz(22))

if __name__ == ("__main__"):
    main()



