// Problem Statement
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), 
// write a function to check whether these edges make up a valid tree.

// Constraints:
// - No duplicate edges will appear in edges.
// - Since all edges are undirected, [0, 1] is the same as [1, 0] and will not appear together in edges.

// Examples:

// Example 1:
// Input: n = 5, edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
// Output: true

// Example 2:
// Input: n = 5, edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]]
// Output: false

class Solution {
public:
    /**
     * @param n: An integer
     * @param edges: a list of undirected edges
     * @return: true if it's a valid tree, or false
     */
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (neighbor == parent) continue;
            if (visited[neighbor] || dfs(neighbor, node, adj, visited)) return true;
        }
        return false;
    }

    bool validTree(int n, vector<vector<int>> &edges) {
        if (edges.size() != n - 1) return false;

        vector<vector<int>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        if (dfs(0, -1, adj, visited)) return false;

        for (bool isVisited : visited) {
            if (!isVisited) return false;
        }

        return true;
    }
};
