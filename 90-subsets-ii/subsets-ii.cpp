class Solution {
public:
    void fng(vector<int>& nums, set<vector<int>>& st, vector<int>& res, int i){
        if(i == nums.size()){
            st.insert(res);
            return;
        }

        res.push_back(nums[i]);
        fng(nums, st, res, i + 1);

        int idx = i + 1;
        while(idx < nums.size() && nums[idx] == nums[idx - 1]) idx++;

        res.pop_back();
        fng(nums, st, res, idx);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        set<vector<int>> st;
        vector<int> res;
        vector<vector<int>> ans;

        fng(nums, st, res, 0);

        for(auto it : st) ans.push_back(it);
        return ans;
    }
};