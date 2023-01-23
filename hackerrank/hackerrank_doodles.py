##!/usr/bin/env python
'''
    @author [mst]
    @brief  HackerRank solutions doodle space

    @version 0.1 2022.12
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

    # make a set to remove dupes
    # turn back to list
    # sort it
    # take the pre-last member
    print(sorted(list(set(arr)))[-2])

def nested_lists():

    students = [['Harry', 37.21], ['Berry', 37.21], ['Tina', 37.2], ['Akriti', 41], ['Harsh', 39]]
    scores = {}
    for n in students:
        scores[n[1]] = n[0]

    # res = {key: val for key, val in sorted(scores.items(), key = lambda ele: ele[1])}
    # res = {key: val for key, val in sorted(scores.items(), key = lambda ele: ele[1])}
    # print (res)

    # students = []
    # for _ in range(int(input())):
    #     name = input()
    #     score = float(input())
    #     students.append([name,score])
    minimal = 100
    for i in range(len(students)):
        if minimal > float(students[i][1]):
            minimal = float(students[i][1])
    runner = 100
    for i in range(len(students)):
        if float(students[i][1]) > float(minimal) and runner > float(students[i][1]):
            runner = float(students[i][1])
    runner_arr = []
    for i in range(len(students)):
        if float(students[i][1]) == float(runner):
            runner_arr.append(students[i][0])
    runner_arr = sorted(runner_arr)
    for i in range(len(runner_arr)):
        print(runner_arr[i])

def days30_arrays():

    arr = [[1,1,1,0,0,0],
           [0,1,0,0,0,0],
           [1,1,1,0,0,0],
           [0,0,2,4,4,0],
           [0,0,0,2,0,0],
           [0,0,1,2,4,0]]

    max_sum = (6*6*(-9))
        
    # matrix dimensions are hard coded 6x6
    for i in range(1,5):
        for j in range(1,5):
            hg_sum = arr[i-1][j-1]+arr[i-1][j]+arr[i-1][j+1]+arr[i][j]+arr[i+1][j-1]+arr[i+1][j]+arr[i+1][j+1]
            print(f"{arr[i-1][j-1]} {arr[i-1][j]} {arr[i-1][j+1]}\n  {arr[i][j]}\n{arr[i+1][j-1]} {arr[i+1][j]} {arr[i+1][j+1]}")
            if hg_sum > max_sum: max_sum = hg_sum

    print(max_sum)


def py_lists():    
    N = int(input())
    l1 = []
    for i in range(N):
        # [demo] treating variable elements inputs
        line = input().split()
        
        if line[0] == "print":
            print(l1)
        elif line[0] == "insert":
            l1.insert(int(line[1]),int(line[2]))
        elif line[0] == "remove":
            l1.remove(int(line[1]))
        elif line[0] == "pop":
            l1.pop()
        elif line[0] == "append":
            l1.append(int(line[1]))
        elif line[0] == "sort":
            l1.sort()
        else:
            l1.reverse()

def count_substring():
    string, sub_string = "ABCDCDC","CDC"

    sub_length = len(sub_string)

    count = 0
    for i in range(len(string)-sub_length+1):
        if (string[i:i+sub_length] == sub_string):
            count += 1
    
    print (count)
    return count


def print_rangoli(n):
    # your code goes here
    import string

    # [demo] a string with all lowercase letters
    alpha = string.ascii_lowercase
    print(alpha)
    
    L = []
    for i in range(n):
        s = "-".join(alpha[i:n])
        L.append((s[::-1]+s[1:]).center(4*n-3, "-"))
        
    print('\n'.join(L[:0:-1]+L))

################## DRIVER
def main():

    print ("[mst] hackerrank doodle")
    # challenge2()
    # is_leap()
    # list_comprehensions()
    # runner_up()
    # nested_lists()
    # days30_arrays()

    # py_lists()
    # count_substring()
    print_rangoli(5)




if __name__ == ("__main__"):
    main()
