/**
    @author [mst]
    @brief  leetcode series
    2316_count_unreachable_pairs
    You are given an integer n. There is an undirected graph with n nodes, numbered from 0 to n - 1. You are given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.
    Return the number of pairs of different nodes that are unreachable from each other.

    gains:
    -wip

    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <numeric>        // accumulate usage
using namespace std;


////////////////// DECL_IMPL


// initaial naive approach: count over all connections. problem: subsequent connections are needed to be taken into account
class Solution0 {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {

        // make an adjacency list for dfs
        // since ai != bi, we can simply count the connections for each node
        // unordered_map<int,vector<int>> adj(n);
        vector<int> adj(n);
        for (vector<int> &edge : edges) {
            // int u = edge[0]; // align to a 0 based numbering
            // int v = edge[1];
            adj[edge[0]]++;
            adj[edge[1]]++; // [bp] bi-directional graph
            // adj[u].push_back(v);
            // adj[v].push_back(u); // [bp] bi-directional graph
        }

        int lacking = 0;

        for (auto v: adj) {
            lacking += (n-1) - v;
        }

        return lacking;
    }
};


// snipped
//
// sub: 79 39
class Solution
{
public:
    long long countPairs(int n, vector<vector<int>> &edges)
    {
        long long ans = 0;
        vector<vector<int>> graph(n);
        vector<bool> seen(n);
        int unreached = n;

        for (const vector<int> &edge : edges)
        {
            const int u = edge[0];
            const int v = edge[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        for (int i = 0; i < n; ++i)
        {
            const int reached = dfs(graph, i, seen);
            unreached -= reached;
            ans += static_cast<long long>(unreached) * reached;
        }
        return ans;
    }

private:
    int dfs(const vector<vector<int>> &graph, int u, vector<bool> &seen)
    {
        if (seen[u])
            return 0;
        seen[u] = true;
        return accumulate(
            begin(graph[u]), end(graph[u]), 1,
            [&](int subtotal, int v)
            { return subtotal + dfs(graph, v, seen); });
    }
};

////////////////// DRIVER
int main() {
    Solution s;

    // int n = 3;
    // vector<vector<int>> arr = {{0,1},{0,2},{1,2}};
    int n = 7;
    vector<vector<int>> arr = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    int res = s.countPairs(n,arr);
    cout << res;

    return 0;
}