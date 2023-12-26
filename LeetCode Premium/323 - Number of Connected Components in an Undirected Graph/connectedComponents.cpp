class Solution {
public:
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visisted) {
        visisted[node] = true;
        for (auto &i : adj[node]) {
            if (!visisted[i]) {
                dfs(i, adj, visisted);
            }
        }
    }
    int countComponents(int n, vector<vector<int>> &edges) {
        vector<vector<int>> adj(n);
        for (auto &i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<bool> visisted(n, false);
        int connectedComponents = 0;
        for (int i = 0; i < n; i++) {
            if (!visisted[i]) {
                connectedComponents++;
                dfs(i, adj, visisted);
            }
        }
        return connectedComponents;
    }
};
