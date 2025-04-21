// Problem Statement
// You are given an m x n 2D grid initialized with these three possible values:
// -1: A wall or an obstacle.
//  0: A gate.
//  INF: Infinity (2147483647) represents an empty room. Assume the distance to a gate is less than 2147483647.

// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, that room should remain filled with INF.

// Examples:

// Example 1:
// Input:
// [[2147483647,-1,0,2147483647],
//  [2147483647,2147483647,2147483647,-1],
//  [2147483647,-1,2147483647,-1],
//  [0,-1,2147483647,2147483647]]

// Output:
// [[3,-1,0,1],
//  [2,2,1,-1],
//  [1,-1,2,-1],
//  [0,-1,3,4]]

// Example 2:
// Input:
// [[0,-1],
//  [2147483647,2147483647]]

// Output:
// [[0,-1],
//  [1,2]]

class Solution {
public:
    /**
     * @param rooms: m x n 2D grid
     * @return: nothing
     */
    void wallsAndGates(vector<vector<int>> &rooms) {
        int n = rooms.size();
        if (n == 0) return;
        int m = rooms[0].size();

        queue<pair<int, int>> q;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (rooms[i][j] == 0) {
                    q.push({i, j});
                }
            }
        }

        int dx[4] = {-1, 0, 1, 0};
        int dy[4] = {0, 1, 0, -1};

        while (!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx >= 0 && nx < n && ny >= 0 && ny < m && rooms[nx][ny] == 2147483647) {
                    rooms[nx][ny] = rooms[x][y] + 1;
                    q.push({nx, ny});
                }
            }
        }
    }
};
