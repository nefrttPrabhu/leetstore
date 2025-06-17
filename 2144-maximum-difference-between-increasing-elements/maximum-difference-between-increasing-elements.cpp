class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int maxi = -1;
        int mini = nums[0];

        for(int j = 1; j < nums.size(); j++) {
            if(nums[j] > mini) {
                maxi = max(maxi, nums[j] - mini);
            } 
            else {
                mini = nums[j]; 
            }
        }

        return maxi;
    }
};
