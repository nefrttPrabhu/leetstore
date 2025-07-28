class Solution {
public:
    int helper(vector<vector<int>>& dp, int row, int col){
        if(dp[row][col] != -1) return dp[row][col];

        if(row == 0 && col == 0){
            return 1;
        }

        if(row < 0 || col < 0){
            return 0;
        }

        int up = 0;
        if(col > 0) up = helper(dp, row, col - 1);

        int down = 0;
        if(row > 0) down = helper(dp, row - 1, col);

        return dp[row][col] = down + up;
    }

    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));
        int a = helper(dp, m - 1, n - 1);
        return a;
    }
};