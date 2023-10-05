/**
    @author [mst]
    @brief  leetcode series
    706_design_hashmap
    Design a HashMap without using any built-in hash table libraries.
    Implement the MyHashMap class:
    MyHashMap() initializes the object with an empty map.
    void put(int key, int value) inserts a (key, value) pair into the HashMap. If the key already exists in the map, update the corresponding value.
    int get(int key) returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key.
    void remove(key) removes the key and its corresponding value if the map contains the mapping for the key.

    gains:
    -simple cpp structs manipulation


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <list>
using namespace std;


////////////////// DECL_IMPL

// snipped
//
// sub 56, 55
class MyHashMap
{
public:
  MyHashMap() : lists(kSize) {}

  void put(int key, int value)
  {
    auto &pairs = lists[key % kSize];
    for (auto &[k, v] : pairs)
      if (k == key)
      {
        v = value;
        return;
      }
    pairs.emplace_back(key, value);
  }

  int get(int key)
  {
    const list<pair<int, int>> &pairs = lists[key % kSize];
    for (const auto &[k, v] : pairs)
      if (k == key)
        return v;
    return -1;
  }

  void remove(int key)
  {
    auto &pairs = lists[key % kSize];
    for (auto it = pairs.begin(); it != pairs.end(); ++it)
      if (it->first == key)
      {
        pairs.erase(it);
        return;
      }
  }

private:
  static constexpr int kSize = 10000;
  vector<list<pair<int, int>>> lists;
};

////////////////// DRIVER
int main()
{
    MyHashMap myHashMap = MyHashMap();
    myHashMap.put(1, 1); // The map is now [[1,1]]
    myHashMap.put(2, 2); // The map is now [[1,1], [2,2]]
    myHashMap.get(1);    // return 1, The map is now [[1,1], [2,2]]
    myHashMap.get(3);    // return -1 (i.e., not found), The map is now [[1,1], [2,2]]
    myHashMap.put(2, 1); // The map is now [[1,1], [2,1]] (i.e., update the existing value)
    myHashMap.get(2);    // return 1, The map is now [[1,1], [2,1]]
    myHashMap.remove(2); // remove the mapping for 2, The map is now [[1,1]]
    myHashMap.get(2);    // return -1 (i.e., not found), The map is now [[1,1]]

    return 0;
}