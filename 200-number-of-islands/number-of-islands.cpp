class Solution {
public:
    int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void bfs(vector<vector<int>>& vis, vector<vector<char>>& grid, int row, int col) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> q;
        q.push({row, col});
        vis[row][col] = 1;

        while (!q.empty()) {
            auto [r, c] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int nr = r + directions[k][0];
                int nc = c + directions[k][1];

                if (nr >= 0 && nr < n && nc >= 0 && nc < m &&
                    vis[nr][nc] == 0 && grid[nr][nc] == '1') {
                    vis[nr][nc] = 1;
                    q.push({nr, nc});
                }
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int cnt = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    cnt++;
                    bfs(vis, grid, i, j);
                }
            }
        }
        return cnt;
    }
};