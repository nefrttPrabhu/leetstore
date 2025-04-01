class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n + 1, 0);
        
        for (int i = n - 1; i >= 0; i--) {
            int points = questions[i][0];
            int brainpower = questions[i][1];
            
            dp[i] = dp[i + 1];
            
            int next_question = i + brainpower + 1;
            if (next_question < n) {
                dp[i] = max(dp[i], (long long)points + dp[next_question]);
            } else {
                dp[i] = max(dp[i], (long long)points);
            }
        }
        
        return dp[0];
    }
};
