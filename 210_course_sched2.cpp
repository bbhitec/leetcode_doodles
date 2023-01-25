//
// [mst] 210_course_sched2.cpp
// leetcode problems series
//
//  210. Course Schedule II
//  There are a total of n courses you have to take labelled from 0 to n - 1.
//  Some courses may have prerequisites, for example, if prerequisites[i] = [ai, bi] this means you must take the course bi before the course ai.
//  Given the total number of courses numCourses and a list of the prerequisite pairs, return the ordering of courses you should take to finish all courses.
//  If there are many valid answers, return any of them.If it is impossible to finish all courses, return an empty array.
//
// features, changelog:
// - initial 2020.11
// - topological sort with dfs based on: https://youtu.be/qe_pQCh09yU
// - 2020.12: submission refused due to running time exeeded
// - [wip] solve with kahn's bfs topological sort as in: https://youtu.be/tggiFvaxjrY
//

////////////////// LIBS
#include <iostream>            // usage of console prints
#include <vector>
#include <stack>

using namespace std;

#define DEBUG 1

class Solution {

public:

	// this will find a possible schedule to attend all courses given aprereqs array (or an empty array if impossible)
	// we will use topological sort: sorting all in order of their dependencies
	// -it requers DAG (directed acyclic graph). meaning, return empty array if a cycle is detected
	// -nodes with indegree 0 will be at the head of the list
	// -nodes with outdegree 0 will be at the end of the list (or not in the traversal)
	//
	// time O(V+E)
	vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

		vector<int> result;		// will hold the resulted schedule, or will be empty if impossible

		// build a friendlier adjacency matrix
		// each directed edge shows accessible courses to be taken
		vector<vector<int>> adj(numCourses);
		int edges = prerequisites.size();
		for (int i = 0; i < edges; i++) {
			adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
		}
		if (DEBUG) print_adjacency(adj,numCourses);

		// we need a DAG, so first detect any cycles
		if (check_cycles(adj, numCourses)) {
			if (DEBUG) cout << "cycle detected!" << endl;
			return result; // this will return an epty vector at this point
		}

		// run a topology sort with dfs
		stack<int> dfs_stack;
		vector<bool> visited(numCourses, false);

		for (int node = 0; node < numCourses; node++) {
			if (!visited[node]) dfs_topo(adj, node, visited, dfs_stack);
		}

		// return possible traversal in suitable orded
		while (!dfs_stack.empty()) {
			result.push_back(dfs_stack.top());
			dfs_stack.pop();
		}

		return result;
	}

	// assisting functions

	// dfs traversal for topology sort
	void dfs_topo(vector<vector<int>> adj, int curr, vector<bool> &visited, stack<int> &stack) {
		visited[curr] = true;

		for (auto const neighbor : adj[curr]) {
			if (visited[neighbor] == false) {
				dfs_topo(adj, neighbor, visited, stack);
			}
		}
		stack.push(curr);
	}


	// utility recursion for the cyclic check
	bool cycle_recursion(vector<vector<int>> adj, vector<bool> visited, int curr) {
		if (visited[curr]) return true;

		visited[curr] = true;
		bool cycle = false;
		// follow each of this nodes adjacencies
		for (int i = 0; i < adj[curr].size(); i++) {
			cycle = cycle_recursion(adj, visited, adj[curr][i]);
			cout << "cycle detected. path over node: " << curr << endl;	// the first time this is printed is the cycle detection
			if (cycle) return true;
		}
		return false;	// no cycle found in inner traversal
	}

	// spot cycles in a graph
	// [wiki] follow notes in graphs2 cs proj
	bool check_cycles(vector<vector<int>> adj, int N) {
		vector<bool> visited(N, false);
		bool cycle = false;	// this flag will help us track the inner recursive check

		for (auto node = 0; node < N; node++) {
			// mark node visited tor inner-traversal
			visited[node] = true;

			// follow the neighbors
			for (int neighbor = 0; neighbor < adj[node].size(); neighbor++) {
				// this will kickstart the recursion which will do the actual traversal
				cycle = cycle_recursion(adj, visited, adj[node][neighbor]);
				if (cycle) return true;
			}

			// reset the node as unvisited
			visited[node] = false;
		}
		return false;
	}

	// print the graph's adjacency list
	// use reference to vector of vectors to avoid unnecessary copying
	void print_adjacency(vector<vector<int>> adj, int N) {
		cout << "Adjacency list (edges list): " << endl;

		for (int i = 0; i < N; i++) {
			for (const auto n : adj[i]) {
				cout << "[" << i << "," << n << "]";
			}
			cout << endl;
		}
	}
};

// simple vector printout
template <typename T>
void print_vec(vector<T> vec) {
	cout << "[";
	int i{ 0 };
	for (const auto &member : vec) {
		cout << member;
		if (i < vec.size() - 1) { // [demo] manual index in for-each loop. conditonal semicolon
			cout << ",";
			i++;
		}
	}
	cout << "]" << endl;
}


////////////////// DRIVER
int main()
{
	cout << "[mst] leetcode 210. course schedule 2" << endl << endl;
	Solution sol;

	// Case 1
	// Input: numCourses = 2, prerequisites = [[1,0]]
	// Output: [0, 1]
	// Explanation: There are a total of 2 courses to take.To take course 1 you
	// should have finished course 0. So the correct course order is[0, 1].
	//
	cout << "Case 1" << endl;
	int numCourses = 2;
	vector<vector<int>> prerequisites = { {1,0} };
	vector<int> order = sol.findOrder(numCourses, prerequisites);
	cout << "possible schedule: "; print_vec(order); order.clear();	// show result and clear it for reuse


	// Case 2
	// Input: numCourses = 4, prerequisites = [[1, 0], [2, 0], [3, 1], [3, 2]]
	// Output : [0, 2, 1, 3]
	//
	cout << endl << endl << "Case 2" << endl;
	numCourses = 4;
	prerequisites = { {1,0},{2,0},{3,1},{3,2} };
	order = sol.findOrder(numCourses, prerequisites);
	cout << "possible schedule: "; print_vec(order); order.clear();

	// Case 3
	// testing a cycle detection
	//
	cout << endl << endl << "Case 3: cyclical graph" << endl;
	numCourses = 3;
	prerequisites = { { 1,0 },{ 2,1 },{ 0,2 } };
	order = sol.findOrder(numCourses, prerequisites);
	cout << "possible schedule: "; print_vec(order); order.clear();

	// Case 4
	// Input: numCourses = 1, prerequisites = []
	// Output: [0]
	//
	cout << endl << endl << "Case 4: empty graph" << endl;
	numCourses = 1;
	prerequisites = {};
	order = sol.findOrder(numCourses, prerequisites);
	cout << "possible schedule: "; print_vec(order); order.clear();

	// Case 4
	// Input: numCourses = 1, prerequisites = []
	// Output: [5, 4, 0, 3, 1, 2]
	//
	cout << endl << endl << "Case 5: medium graph" << endl;
	numCourses = 6;
	prerequisites = { {2,0},{3,0},{1,3},{2,4},{1,4},{0,5},{2,5} };
	order = sol.findOrder(numCourses, prerequisites);
	cout << "possible schedule: "; print_vec(order); order.clear();

	std::cin.get(); // pseudo-pause the console
	return 0;
}
