##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    950_reveal_cards
    You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].

    You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.

    You will do the following steps repeatedly until all cards are revealed:

    Take the top card of the deck, reveal it, and take it out of the deck.
    If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
    If there are still unrevealed cards, go back to step 1. Otherwise, stop.
    Return an ordering of the deck that would reveal the cards in increasing order.

    Note that the first entry in the answer is considered to be the top of the deck.


    gains:
    -deque in python


    @version 2024.04
'''


from collections import deque

# sort the deck decreasingly, add the sorted values to a dequeue while rotating it every entry, simulating the card's return to the botton during the play
# assisted
#
# sub 74 97
class Solution:
    def deckRevealedIncreasing(self, deck: [int]) -> [int]:
        dq = deque()

        for card in reversed(sorted(deck)):
            dq.rotate()
            dq.appendleft(card)

        return list(dq)

################## DRIVER
def main():
    sol = Solution()

    deck  = [17,13,11,2,3,5,7]

    res = sol.deckRevealedIncreasing(deck)
    print (res)



if __name__ == ("__main__"):
    main()
