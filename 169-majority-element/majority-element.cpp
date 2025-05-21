class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int ans = 0;

        for(auto it : nums){
            if(!count){
                ans = it;
            }
            count += (it == ans) ? 1 : -1;
        }
        return ans;
    }
};