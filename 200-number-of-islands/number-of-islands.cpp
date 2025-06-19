class Solution {
public:
    int directions[4][2] = {{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

    void fng(vector<vector<int>>& vis, vector<vector<char>>& grid, int row, int col) {
        int n = grid.size(), m = grid[0].size();
        vis[row][col] = 1;

        for (int k = 0; k < 4; k++) {
            int nr = row + directions[k][0];
            int nc = col + directions[k][1];

            if (nr >= 0 && nr < n && nc >= 0 && nc < m && vis[nr][nc] == 0 && grid[nr][nc] == '1') {
                fng(vis, grid, nr, nc);
            }
        }
    }

    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size(), res = 0;
        vector<vector<int>> vis(n, vector<int>(m, 0));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (vis[i][j] == 0 && grid[i][j] == '1') {
                    res++;
                    fng(vis, grid, i, j);
                }
            }
        }
        return res;
    }
};
