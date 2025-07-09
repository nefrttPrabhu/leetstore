class Solution {
public:
    void backtrack(vector<int>& nums, vector<bool>& vis, vector<int>& res, vector<vector<int>>& ans) {
        if (res.size() == nums.size()) {
            ans.push_back(res);
            return;
        }
        
        for (int i = 0; i < nums.size(); ++i) {
            if (vis[i]) continue;
            vis[i] = 1;
            res.push_back(nums[i]);

            backtrack(nums, vis, res, ans);
            res.pop_back();
            vis[i] = 0;
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        vector<bool> vis(nums.size(), 0);
        
        backtrack(nums, vis, res, ans);
        return ans;
    }
};
