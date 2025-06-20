class Solution {
public:
using p = pair<int,int>;
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int m = image.size();
        int n = image[0].size();
        queue<p>q;
        vector<vector<int>> dir = {{0,1}, {1,0}, {-1,0}, {0,-1}};
        int originalColor = image[sr][sc];
        
        if(image[sr][sc] == color){
            return image;
        }

        image[sr][sc] = color;
        q.push({sr, sc});

        while(!q.empty()){
            int size = q.size();
            while(size--){
                auto node = q.front();
                q.pop();
                for(int  i = 0;i < 4; i++){
                    int a = node.first + dir[i][0];
                    int b = node.second + dir[i][1];
                    if(a >= 0 && a < m && b >= 0 && b < n && image[a][b] == originalColor) {
                        image[a][b] = color; 
                        q.push({a, b});
                    }
                }
            }
        }
    return image;
    }
};