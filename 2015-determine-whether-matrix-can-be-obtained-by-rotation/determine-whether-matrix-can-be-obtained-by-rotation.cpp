class Solution {
public:
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        
        for (int i = 0; i < 4; i++) {
            if (mat == target) return true;
            rotateMatrix(mat);
        }
        
        return false;
    }
    
private:
    void rotateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        vector<vector<int>> rotated(n, vector<int>(n));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                rotated[j][n - 1 - i] = mat[i][j];
        
        mat = rotated;
    }
};
