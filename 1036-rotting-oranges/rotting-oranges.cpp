class Solution {
public:
    using p = pair<int,int>;
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        queue<p>q;
        int time = -1;
        int fresh = 0;
        vector<vector<int>> dir = {{0,1}, {1,0}, {0,-1}, {-1,0}};

        for(int i = 0;i < m; i++){
            for(int j = 0;j < n; j++){
                if(grid[i][j] == 1){
                    fresh++;
                }
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }

        if(!fresh){
            return 0;
        }

            while(!q.empty()){  
                int size = q.size();
                time++;
                while(size--){ 
                    auto node = q.front();
                    q.pop();
                    for(int i = 0;i < 4; i++){
                    int a = node.first + dir[i][0];
                    int b = node.second + dir[i][1];
                    if(a >= 0 && a < m && b >= 0 && b < n && grid[a][b] == 1){
                        grid[a][b] = 2;
                        q.push({a,b});
                        fresh--;
                    }
                }
            }
        }
        return fresh != 0 ? -1 : time;
    }
};