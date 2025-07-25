class Solution {
public:
    void fng(vector<int> nums, vector<int>& res, set<vector<int>>& ans, int idx){
        if(idx == nums.size()){
            ans.insert(res);
            return;
        }

        res.push_back(nums[idx]);
        fng(nums, res, ans, idx + 1);

        res.pop_back();
        fng(nums, res, ans, idx + 1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> ans;
        vector<vector<int>> a;
        vector<int> res;

        fng(nums, res, ans, 0);
        for(auto it : ans) a.push_back(it);
        return a;
    }
};