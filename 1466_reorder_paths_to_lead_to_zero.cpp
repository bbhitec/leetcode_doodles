/**
    @author [mst]
    @brief  leetcode series
    1466_reorder_paths_to_lead_to_zero
    There are n cities numbered from 0 to n - 1 and n - 1 roads such that there is only one way to travel between two different cities (this network form a tree). Last year, The ministry of transport decided to orient the roads in one direction because they are too narrow.
    Roads are represented by connections where connections[i] = [ai, bi] represents a road from city ai to city bi.
    This year, there will be a big event in the capital (city 0), and many people want to travel to this city.
    Your task consists of reorienting some roads such that each city can visit the city 0. Return the minimum number of edges changed.
    It's guaranteed that each city can reach city 0 after reorder.

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
// sub 97 79
class Solution {
public:
    int minReorder(int n, vector<vector<int>> &connections) {
        vector<vector<int>> graph(n);

        for (const vector<int> &conn : connections) {
            graph[conn[0]].push_back(conn[1]);
            graph[conn[1]].push_back(-conn[0]); // - := conn[0] -> conn[1]
        }

        return dfs(graph, 0, -1);
    }

private:
    int dfs(const vector<vector<int>> &graph, int u, int parent) {
        int change = 0;

        for (const int v : graph[u]) {
            if (abs(v) == parent)
                continue;
            if (v > 0)
                ++change;
            change += dfs(graph, abs(v), u);
        }

        return change;
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    int n = 6;
    vector<vector<int>> connections = {{0,1},{1,3},{2,3},{4,0},{4,5}};
    int res = s.minReorder(n,connections);
    cout << res;

    return 0;
}