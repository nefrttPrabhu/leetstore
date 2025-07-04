class Solution {
public:
    using p = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<p> q;
        int fresh = 0;
        int time = 0;
        vector<vector<int>> dir = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 2) {
                    q.push({i, j});
                }
                if (grid[i][j] == 1) {
                    fresh++;
                }
            }
        }

        if(fresh == 0) return 0;

        while (!q.empty()) {
            int size = q.size();
            time++;
            while (size--) {
                p temp = q.front();
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int x = temp.first + dir[i][0];
                    int y = temp.second + dir[i][1];

                    if (x < n && x >= 0 && y < m && y >= 0 && grid[x][y] == 1) {
                        grid[x][y] = 2;
                        q.push({x, y});
                        fresh--;
                    }
                }
            }
        }
        return fresh != 0 ? -1 : time - 1;
    }
};