/**
    @author [mst]
    @brief  leetcode series
    684_redundant_connection
    Medium
    In this problem, a tree is an undirected graph that is connected and has no cycles.
    You are given a graph that started as a tree with n nodes labeled from 1 to n, with one additional edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed. The graph is represented as an array edges of length n where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the graph.
    Return an edge that can be removed so that the resulting graph is a tree of n nodes. If there are multiple answers, return the answer that occurs last in the input.

    gains:
    -undirected graphs with cpp
    -union find with ranking score


    @version 0.1 2023.06
*/



////////////////// LIBS
#include <iostream>     // usage of console prints
#include <vector>
#include <numeric>
using namespace std;


////////////////// DECL_IMPL

// util
void print_vec(vector<int> vec) {
  for(auto &v:vec)
    cout<<v<<", ";
};


// union find approach: keep a rank (connected union size) and a parent arrays for each
// edge, check if both nodes connected to the same union (i.e. same parent) to find the redundand edge
// otherwise merge the nodes (connect lower ranked node to a higher ranked node) as you go.
//
// sub 100 26
class Solution {
  private:
      vector<int> parent;
      vector<int> rank;

      int find(int u) {
        if (parent[u] == u) return u;
        else return find(parent[u]);
      }

      bool unionRank(int u, int v) {
        // find a more connected node of the pair
        const int i = find(u);
        const int j = find(v);
        if (i == j) return false; // nodes in the same union

        // connect to a higher order union
        if (rank[i]<rank[j]) {
          parent[i] = j;
        } else if (rank[i]>rank[j]) {
            parent[j] = i;
        } else {
          parent[i] = j;
          rank[j]++;
        }
        return true;
      }

public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
      parent.assign(edges.size() + 1, 0);
      rank.assign(edges.size() + 1, 0);
      iota(parent.begin(), parent.end(), 0);

      for (const vector<int>& edge : edges) {
        if (!unionRank(edge[0], edge[1]))
          return edge;
      }
      throw;
		}
};



// assisted
// using same approach but a dedicated class
//
// sub 88 29
class UnionFind {
public:
  UnionFind(int n) : id(n), rank(n) {
    iota(id.begin(), id.end(), 0);
  }

  bool unionByRank(int u, int v) {
    const int i = find(u);
    const int j = find(v);
    if (i == j)
      return false;
    if (rank[i] < rank[j]) {
      id[i] = j;
    } else if (rank[i] > rank[j]) {
      id[j] = i;
    } else {
      id[i] = j;
      ++rank[j];
    }
    return true;
  }

private:
  vector<int> id;
  vector<int> rank;

  int find(int u) {
    return id[u] == u ? u : id[u] = find(id[u]);
  }
};

class Solution2 {
public:
  vector<int> findRedundantConnection(vector<vector<int>>& edges) {
    UnionFind uf(edges.size() + 1);

    for (const vector<int>& edge : edges) {
      const int u = edge[0];
      const int v = edge[1];
      if (!uf.unionByRank(u, v))
        return edge;
    }

    throw;
  }
};



////////////////// DRIVER
int main()
{
    Solution s;

    // vector<vector<int>> edges = {{1,2},{1,3},{2,3}};
    vector<vector<int>> edges = {{1,2},{2,3},{3,4},{1,4},{1,5}};
    vector<int> res = s.findRedundantConnection(edges);

    for (auto &i : res) {
      cout << i << ", ";
    }

    return 0;
}