
class Solution {
public:
    void backtrack(vector<int>& candidates, int tar, int idx, vector<int>& res, vector<vector<int>>& ans) {
        if (tar == 0) {
            ans.push_back(res);
            return;
        }
        for (int i = idx; i < candidates.size(); ++i) {
            if (i > idx && candidates[i] == candidates[i - 1])
            continue;

            if (candidates[i] > tar) break; 

            res.push_back(candidates[i]);
            backtrack(candidates, tar - candidates[i], i + 1, res, ans);
            res.pop_back(); 
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int tar) {
        vector<vector<int>> ans;
        vector<int> res;
        
        sort(candidates.begin(), candidates.end()); 
        backtrack(candidates, tar, 0, res, ans);
        return ans;
    }

};