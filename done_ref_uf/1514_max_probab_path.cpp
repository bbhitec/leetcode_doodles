/**
    @author [mst]
    @brief  leetcode series
    1514_max_probab_path
	You are given an undirected weighted graph of n nodes (0-indexed), represented by an edge list where edges[i] = [a, b] is an undirected edge connecting the nodes a and b with a probability of success of traversing that edge succProb[i].
    Given two nodes start and end, find the path with the maximum probability of success to go from start to end and return its success probability.
    If there is no path from start to end, return 0. Your answer will be accepted if it differs from the correct answer by at most 1e-5.

    gains:
    -[wip] rd the solution
    -graphs: building adjacency lists, traversal


    @version 0.1 2023.04
*/



////////////////// LIBS
#include <iostream>         // usage of console prints
#include <vector>
#include <queue>
using namespace std;


////////////////// DECL_IMPL


// snipped
//
// sub 83 45
class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start, int end) {
        const int sz = edges.size();

        // use max heap to combine probabilities (get highest probab in O(1) time)
        priority_queue<pair<double, int>> maxHeap;
        maxHeap.emplace(1.0, start);
        vector<bool> seen(n);

        // build an adjacency list
        vector<vector<pair<int, double>>> graph(sz);
        for (int i = 0; i < sz; i++) {
            const int u = edges[i][0];
            const int v = edges[i][1];
            const double probab = succProb[i];
            graph[u].emplace_back(v,probab);
            graph[v].emplace_back(u,probab);    // undirected graph!
        }

        // // testing: print the entire graph
        // int j = 0;
        // for (const vector<pair<int, double>> &node : graph) {
        //     for (int i = 0; i < node.size(); i++) {
        //         cout << "node " << j << " to " << node[i].first<< " probab " << node[i].second  << endl;
        //     }
        //     j++;
        // }

        while (!maxHeap.empty()) {
            // resolve path
            const auto [prob, u] = maxHeap.top();
            maxHeap.pop();
            if (u == end) return prob;  // reaching the end

            // note visited node
            if (seen[u]) continue;
            seen[u] = true;

            // push next neighbors to check in the following iteration
            for (const auto &[nextNode, edgeProb] : graph[u]) {
                if (seen[nextNode]) continue;
                maxHeap.emplace(prob * edgeProb, nextNode);
            }
        }

        return 0;   // 'end' not reached
    }
};

////////////////// DRIVER
int main()
{
    Solution s;

    int n = 3, start = 0, end = 2;
    vector<vector<int>> edges = {{0,1},{1,2},{0,2}};
    vector<double> succProb = {0.5,0.5,0.2};

    double res = s.maxProbability(n, edges, succProb, start, end);
    cout << res;

    return 0;
}