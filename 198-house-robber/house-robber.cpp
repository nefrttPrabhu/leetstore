class Solution {
public:
int t[101];
int solve(vector<int> &nums, int jumps, int n){
    if(jumps >= n){
        return 0;
    }

    if(t[jumps] != -1){
        return t[jumps];
    }

    int earn = nums[jumps] + solve(nums, jumps + 2, n);
    int skip = solve(nums, jumps + 1, n);

    return t[jumps] = max(earn, skip);
}
    int rob(vector<int>& nums) {
        int n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(nums, 0, n);
    }
};