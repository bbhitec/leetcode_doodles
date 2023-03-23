/**
    @author [mst]
    @brief  leetcode series
    1319_ops_to_network
	There are n computers numbered from 0 to n - 1 connected by ethernet cables connections forming a network where connections[i] = [ai, bi] represents a connection between computers ai and bi. Any computer can reach any other computer directly or indirectly through the network.
	You are given an initial computer network connections. You can extract certain cables between two directly connected computers, and place them between any pair of disconnected computers to make them directly connected.
	Return the minimum number of times you need to do this in order to make all the computers connected. If it is not possible, return -1.

    gains:
	-graphs in cpp


    @version 0.1 2023.02
*/


////////////////// LIBS
#include <iostream>				// usage of console prints
#include <vector>
#include <unordered_set>		// storing seen vertices
using namespace std;


////////////////// DECL_IMPL

// snipped
//
// sub 18 12
class Solution {
public:
	int makeConnected(int n, vector<vector<int>> &connections) {
		// To connect n nodes, we need at least n - 1 edges
		if (connections.size() < n - 1)
			return -1;

		int numOfConnected = 0;
		vector<vector<int>> graph(n);
		unordered_set<int> seen;

		for (const vector<int> &conn : connections) {
			graph[conn[0]].push_back(conn[1]);
			graph[conn[1]].push_back(conn[0]);
		}

		for (int i = 0; i < n; ++i)
			if (seen.insert(i).second) {
				dfs(graph, i, seen);
				++numOfConnected;
			}

		return numOfConnected - 1;
	}

private:
	void dfs(const vector<vector<int>> &graph, int u, unordered_set<int> &seen) {
		for (const int v : graph[u])
			if (seen.insert(v).second)
				dfs(graph, v, seen);
	}
};

////////////////// DRIVER
int main()
{
	Solution s;
	int n = 4;
	vector<vector<int>> connections = {{0,1},{0,2},{1,2}};
	cout << s.makeConnected(n, connections);
	return 0;
}
