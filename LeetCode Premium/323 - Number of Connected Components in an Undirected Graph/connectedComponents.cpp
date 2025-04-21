// Problem Statement
// In this problem, there is an undirected graph with `n` nodes. 
// The `edges` array represents the edges in the graph, where edges[i] = [a, b] means there is an edge between node `a` and node `b`.

// You need to return the number of connected components in the graph.

// Examples:

// Example 1:
// Input:
// 3
// [[0,1], [0,2]]
// Output:
// 1

// Example 2:
// Input:
// 6
// [[0,1], [1,2], [2,3], [4,5]]
// Output:
// 2

class Solution {
public:
    /**
     * @param n: the number of vertices
     * @param edges: the edges of undirected graph
     * @return: the number of connected components
     */
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor, adj, visited);
            }
        }
    }

    int countComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (const auto &edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        int connectedComponents = 0;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                connectedComponents++;
                dfs(i, adj, visited);
            }
        }

        return connectedComponents;
    }
};
