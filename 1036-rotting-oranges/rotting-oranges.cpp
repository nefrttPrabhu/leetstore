class Solution {
public:
    using p = pair<int, int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int fresh = 0;
        int cnt = -1;

        queue<p> q;

        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i, j});
                }
            }
        }

        if(fresh == 0) return 0;

        vector<vector<int>> dir = {{1, 0}, {0, 1}, {0, -1}, {-1, 0}};
        while(!q.empty()){
            int size = q.size();
            cnt++;
            while(size--){
                p idx = q.front();
                q.pop();

                for(int i = 0; i < 4; i++){
                    int a = idx.first + dir[i][0];
                    int b = idx.second + dir[i][1];

                    if(a < n && a >= 0 && b < m && b >= 0 && grid[a][b] == 1){
                        grid[a][b] = 2;
                        q.push({a, b});
                        fresh--;
                    }
                }
            }
        }
        if(fresh != 0) return -1;
        return cnt;
    }
};