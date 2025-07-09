class Solution {
public:
    void fng(vector<int>& nums, vector<vector<int>>& ans, vector<int>& res, int i){
        if(i == nums.size()){
            ans.push_back(res);
            return ;
        }

        res.push_back(nums[i]);
        fng(nums, ans, res, i + 1);

        res.pop_back();
        fng(nums, ans, res, i + 1);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> res;
        int i = 0;
        fng(nums, ans, res, i);
        return ans;
    }
};