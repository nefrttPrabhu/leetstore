class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<int>>& dirs, int m, int n) {
        if(i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0) return;

        grid[i][j] = 0;

        for(int k = 0; k < 4; k++) {
            dfs(grid, i + dirs[k][0], j + dirs[k][1], dirs, m, n);
        }
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dirs = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        int cnt = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1 && (i == 0 || i == m - 1 || j == 0 || j == n - 1)) {
                    dfs(grid, i, j, dirs, m, n);
                }
            }
        }

        for(int i = 0; i < m; i++ ) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    cnt++;
                }
            }
        }
        return cnt;
    }
};