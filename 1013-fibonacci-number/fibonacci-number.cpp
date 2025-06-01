class Solution {
public:
int ans(vector<int> &dp, int n){
    if(n <= 1){
        return n;
    }
    
    if(dp[n] != -1){
        return dp[n];
    }

    return dp[n] = ans(dp, n - 1) + ans(dp, n - 2);
}
    int fib(int n) {
        if(n <= 1){
            return n;
        }

        vector<int> dp(n + 1, -1);

        return ans(dp, n);
    }
};