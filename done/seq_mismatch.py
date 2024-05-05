

##!/usr/bin/env python
'''
    @author [mst]
    testing first-mismatch vanilla python approach

    @version 2024.04
'''



################## DRIVER
def main():

    seq1 = 'abcdeffghij'
    seq2 = 'abcdefxghij'

    for i in range(len(seq1)):
        if seq1[i] != seq2[i]:
            print(i)
            break



if __name__ == ("__main__"):
    main()
