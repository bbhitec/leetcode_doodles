/**
    @author [mst]
    @brief  leetcode series
    208_implement_trie
    A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.
    Implement the Trie class:
    Trie() Initializes the trie object.
    void insert(String word) Inserts the string word into the trie.
    boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
    boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.

    gains:
    -[wip]


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
struct TrieNode
{
    vector<shared_ptr<TrieNode>> children;
    bool isWord = false;
    TrieNode() : children(26) {}
};

class Trie
{
public:
    void insert(const string &word)
    {
        shared_ptr<TrieNode> node = root;
        for (const char c : word)
        {
            const int i = c - 'a';
            if (node->children[i] == nullptr)
                node->children[i] = make_shared<TrieNode>();
            node = node->children[i];
        }
        node->isWord = true;
    }

    bool search(const string &word)
    {
        shared_ptr<TrieNode> node = find(word);
        return node && node->isWord;
    }

    bool startsWith(const string &prefix)
    {
        return find(prefix) != nullptr;
    }

private:
    shared_ptr<TrieNode> root = make_shared<TrieNode>();

    shared_ptr<TrieNode> find(const string &prefix)
    {
        shared_ptr<TrieNode> node = root;
        for (const char c : prefix)
        {
            const int i = c - 'a';
            if (node->children[i] == nullptr)
                return nullptr;
            node = node->children[i];
        }
        return node;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;


    vector<int> arr = {2,3,4,7,11};
    int k = 5;
    int res = s.findKthPositive(arr,k);
    cout << res;


    return 0;
}