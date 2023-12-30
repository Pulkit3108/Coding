// Description
// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes)
// Write a function to check whether these edges make up a valid tree.

// You can assume that no duplicate edges will appear in edges. 
// Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.

// Input: n = 5 edges = [[0, 1], [0, 2], [0, 3], [1, 4]]
// Output: true.

class Solution {
public:
    bool dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &visited) {
        visited[node] = true;
        for (auto &i : adj[node]) {
            if (i == parent) continue;
            if (visited[i]) return true;
            if (dfs(i, node, adj, visited)) return true;
        }
        return false;
    }
    bool validTree(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visited(n, false);
        if (dfs(0, -1, adj, visited)) return false;
        for (bool i : visited) {
            if (!i) return false;
        }
        return true;
    }
};
