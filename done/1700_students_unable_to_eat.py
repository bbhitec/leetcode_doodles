##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    1700_students_unable_to_eat
    The school cafeteria offers circular and square sandwiches at lunch break, referred to by numbers 0 and 1 respectively. All students stand in a queue. Each student either prefers square or circular sandwiches.
    The number of sandwiches in the cafeteria is equal to the number of students. The sandwiches are placed in a stack. At each step:
    If the student at the front of the queue prefers the sandwich on the top of the stack, they will take it and leave the queue.
    Otherwise, they will leave it and go to the queue's end.
    This continues until none of the queue students want to take the top sandwich and are thus unable to eat.
    You are given two integer arrays students and sandwiches where sandwiches[i] is the type of the i​​​​​​th sandwich in the stack (i = 0 is the top of the stack) and students[j] is the preference of the j​​​​​​th student in the initial queue (j = 0 is the front of the queue). Return the number of students that are unable to eat.

    gains:
    -stack and queue basics in python


    @version 2024.04
'''

# naive: run through the stack and the queue while checking and popping the top elements
# the mismatch is a case whe no matching snadwitches are left in all of the students list
#
# sub 42 95
class Solution:
    def countStudents(self, students: [int], sandwiches: [int]) -> int:
        while (sandwiches and students.count(sandwiches[0])):
            if sandwiches[0] == students[0]:
                sandwiches.pop(0)
                students.pop(0)
            else:
                students.append(students.pop(0))

        return len(sandwiches)




################## DRIVER
def main():
    sol = Solution()

    students = [1,1,0,0]
    sandwiches = [0,1,0,1]

    # students = [1,1,1,0,0,1]
    # sandwiches = [1,0,0,0,1,1]

    res = sol.countStudents(students,sandwiches)
    print (res)



if __name__ == ("__main__"):
    main()
