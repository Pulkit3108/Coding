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
