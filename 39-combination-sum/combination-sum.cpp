class Solution {
public:
    void fng(int ind, vector<int>& arr, int tar, vector<vector<int>>& ans, vector<int>& ds) {
        if (ind == arr.size()) {
            if (tar == 0) {
                ans.push_back(ds);
            }
            return;
        }

        if (arr[ind] <= tar) {
            ds.push_back(arr[ind]);
            fng(ind, arr, tar - arr[ind], ans, ds);
            ds.pop_back();
        }
        fng(ind + 1, arr, tar, ans, ds);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int tar) {
        vector<vector<int>> ans;
        vector<int> ds;

        fng(0, candidates, tar, ans, ds);
        return ans;
    }
};