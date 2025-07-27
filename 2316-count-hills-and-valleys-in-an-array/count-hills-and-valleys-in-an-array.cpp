class Solution {
public:
    int countHillValley(vector<int>& nums) {
        vector<int> ans;
        ans.push_back(nums[0]);
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                ans.push_back(nums[i]);
            }
        }
        int cnt = 0;
        for (int i = 1; i < ans.size() - 1; i++) {
            if(ans[i] > ans[i - 1] && ans[i] > ans[i + 1]) {
                cnt++;
            }
            else if(ans[i] < ans[i - 1] && ans[i] < ans[i + 1]){
                cnt++;
            }
        }
        return cnt;
    }
};
