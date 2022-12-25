##!/usr/bin/env python
'''
    @author [mst]
    @file   <filename>.<extension>    
    @brief  <title or quick description>
    full/optional description: this is a placeholder
    template for new files creation

    features, changelog:
    -2022.05: -initial draft

    @version 0.1 2022.05
'''


def challenge2():
    print ("--challenge2")
    n = int(input().strip())
    if (n%2 == 1) or (n in range(6,21)):
        print("Weird")
    elif (n > 20) or (n in range(2,6)):
        print ("Not Weird")

def is_leap():
    year = int(input())
    print(is_leap(year))

    if year % 400 == 0:
        return True
    elif year % 100 == 0:
        return False
    elif year % 4 == 0:
        return True
    return False

def list_comprehensions():
    # x = int(input())
    # y = int(input())
    # z = int(input())
    # n = int(input())

    x = 1
    y = 1
    z = 2
    n = 3

    # explained: make a list of [i,j,k] elements where each iterate in a geiven range with a condition for the sum
    l1 = [[i,j,k] for i in range(x+1) for j in range(y+1) for k in range(z+1) if (i+j+k != n)]
    print (l1)

def runner_up():
    # n = int(input())
    # arr = map(int, input().split())


    arr = [2,3,6,6,5]
    maximal = 0
    runner_up = 0

    for num in arr:
        if num > maximal: maximal = num
        
    for num in arr:
        if (num < maximal):
            if (num > runner_up):
                runner_up = num

    print(runner_up)


    


################## DRIVER
def main():

    print ("[mst] hackerrank doodle")
    # challenge2()
    # is_leap()
    #list_comprehensions()

    runner_up()
    
    


if __name__ == ("__main__"):
    main()
