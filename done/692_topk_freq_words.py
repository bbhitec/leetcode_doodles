##!/usr/bin/env python
'''
    @author [mst]
    @brief  leetcode problems series
    692_topk_freq_words

    Given an array of strings words and an integer k, return the k most frequent strings.
    Return the answer sorted by the frequency from highest to lowest.
    Sort the words with the same frequency by their lexicographical order.


    gains:
    -python dict (hash) navigation, sorting
    -lexicographical sorting

    @version 0.1 2023.01
'''

# build a hash table with each word as a key and occurance as value,
# sort by value and return 1st k members
#
# sub: 84%T 60%S
class Solution:
    def topKFrequent(self, words: [str], k: int) -> [str]:
        dictionary = {}
        res = []

        # [demo] built in sort can sort strings lexicographically
        words.sort()

        for word in words:
            if word in dictionary: dictionary[word] = dictionary[word] + 1
            else: dictionary[word] = 1

        # [demo] sorting dict by values: results in a list of tuples
        sorted_dict_list = sorted(dictionary.items(), key=lambda x:x[1], reverse=True)
        for i in range(k):
            res.append(sorted_dict_list[i][0])

        # print (res)
        return res

        


################## DRIVER
def main():
    sol = Solution()

    # words = ["i","love","leetcode","i","love","coding"]
    # k = 2        
    # print(f"{sol.topKFrequent(words, k)=}")

    # words = ["the","day","is","sunny","the","the","the","sunny","is","is"]
    # k = 4
    # print(f"{sol.topKFrequent(words, k)=}")

    words=["i","love","leetcode","i","love","coding"]
    k=3
    print(f"{sol.topKFrequent(words, k)=}")


if __name__ == ("__main__"):
    main()
