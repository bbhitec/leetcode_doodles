/**
    @author [mst]
    @brief  leetcode series
    2492_minimum_score
    You are given a positive integer n representing n cities numbered from 1 to n. You are also given a 2D array roads where roads[i] = [ai, bi, distancei] indicates that there is a bidirectional road between cities ai and bi with a distance equal to distancei. The cities graph is not necessarily connected.
    The score of a path between two cities is defined as the minimum distance of a road in this path.
    Return the minimum possible score of a path between cities 1 and n.
    Note:
    A path is a sequence of roads between two cities.
    It is allowed for a path to contain the same road multiple times, and you can visit cities 1 and n multiple times along the path.
    The test cases are generated such that there is at least one path between 1 and n.

    gains:
    -vector manipulation in cpp
    -graph operation and traversal in cpp


    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <queue>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 92 72
class Solution {
public:
    int minScore(int n, vector<vector<int>> &roads) {
        int ans = INT_MAX;
        // a vector of vector of pairs graph[u] := [(v, distance)]
        vector<vector<pair<int, int>>> graph(n);
        queue<int> q{{0}};
        vector<bool> seen(n);
        seen[0] = true;

        // reordering to a different graph
        for (const vector<int> &r : roads) {
            const int u = r[0] - 1;
            const int v = r[1] - 1;
            const int distance = r[2];
            graph[u].emplace_back(v, distance);
            graph[v].emplace_back(u, distance); // [bp] bi-directional graph
        }

        while (!q.empty()) {
            const int u = q.front();    // take first node
            q.pop();
            for (const auto &[v, d] : graph[u]) {   // [demo] great vector orientation
                ans = min(ans, d);  // record minimals

                // queue unseen nodes for traversion
                if (seen[v])
                    continue;
                q.push(v);
                seen[v] = true;
            }
        }

        return ans;
    }
};

////////////////// DRIVER
int main() {
    Solution s;

    vector<vector<int>> arr = {{1,2,9},{2,3,6},{2,4,5},{1,4,7}};
    int n = 4;
    int res = s.minScore(n,arr);
    cout << res;
    return 0;
}