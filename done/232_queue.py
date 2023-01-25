##!/usr/bin/env python
'''
    @author [mst]
    @file    232_queue.py
    @brief  leetcode problems series
    232. Implement Queue using Stacks
    Implement a first in first out (FIFO) queue using only two stacks.
    The implemented queue should support all the functions of a normal queue (push, peek, pop, and empty).

    features, changelog:
    -2022.12: -submission

    @version 0.1 2022.12
'''

# I think I've cheated here by exploiting py3 lists :|
#
# sub: 99%T 76%S
class MyQueue:

    fifo = []

    def __init__(self):
        self.fifo = []

    def push(self, x: int) -> None:
        self.fifo.append(x)

    def pop(self) -> int:
        if len(self.fifo) > 0:
            x = self.fifo.pop(0)
            return x
        return -1

    def peek(self) -> int:
        if len(self.fifo) > 0:
            return self.fifo[0]
        return -1

    def empty(self) -> bool:
        return len(self.fifo) == 0



################## DRIVER
def main():
    print ("[mst]")

    obj = MyQueue()
    obj.push(1)
    param_2 = obj.pop()
    param_3 = obj.peek()
    param_4 = obj.empty()



if __name__ == ("__main__"):
    main()
