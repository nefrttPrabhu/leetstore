class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int> (n, -1));

        dp[0][0] = 1;

        for(int row = 0; row < m; row++) {
            for(int col = 0; col < n; col++) {
                if(row == 0 && col == 0) continue;
                int right = 0;
                if(col > 0) right = dp[row][col - 1];
                int left = 0;
                if(row > 0) left = dp[row - 1][col];

                dp[row][col] = right + left;
            } 
        }
        return dp[m - 1][n - 1];
    }
};
// class Solution {
// public:
//     int helper(int row, int col, vector<vector<int>> &dp) {
//         if(row == 0 && col == 0) return 1;
//         if(dp[row][col] != -1) return dp[row][col];
//         int right = 0;
//         if(col > 0) right = helper(row, col - 1, dp);
//         int down = 0;
//         if(row > 0) down = helper(row - 1, col, dp);
//         return dp[row][col] = right + down;
//     }
//     int uniquePaths(int m, int n) {
//         vector<vector<int>> dp(m, vector<int> (n, -1));
//         return helper(m - 1, n - 1, dp);
//     }
// };