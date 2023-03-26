/**
    @author [mst]
    @brief  leetcode series
    2360_longest_cycle_in_graph
    You are given a directed graph of n nodes numbered from 0 to n - 1, where each node has at most one outgoing edge.
    The graph is represented with a given 0-indexed array edges of size n, indicating that there is a directed edge from node i to node edges[i]. If there is no outgoing edge from node i, then edges[i] == -1.
    Return the length of the longest cycle in the graph. If no cycle exists, return -1.
    A cycle is a path that starts and ends at the same node.

    gains:
    -graph methodology in cpp
    -cycle work in graphs

    @version 0.1 2023.03
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <numeric>        // accumulate usage
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub: 97 90
class Solution {
public:
    int longestCycle(vector<int> &edges) {
        int ans = -1;
        int time = 1;
        vector<int> timeVisited(edges.size());  // this will node time visited as well as check if the node isvalid

        for (int i = 0; i < edges.size(); ++i) {

            if (timeVisited[i]) // don't check visited nodes
                continue;

            // note initial time and run the edges from this node
            const int startTime = time;
            int u = i;  // start node
            while (u != -1 && !timeVisited[u]) {
                timeVisited[u] = time++;
                u = edges[u];   // Move to next node
            }
            if (u != -1 && timeVisited[u] >= startTime)
                ans = max(ans, time - timeVisited[u]);
        }

        return ans;
    }
};

////////////////// DRIVER
int main() {
    Solution s;

    vector<int> edges = {3,3,4,2,3};
    int res = s.longestCycle(edges);
    cout << res;

    return 0;
}