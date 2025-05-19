class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int minValue = nums[0];
        int maxDiff = -1;

        for(int i = 1; i < nums.size(); ++i) {
            if(nums[i] > minValue) {
                maxDiff = max(maxDiff, nums[i] - minValue);
            } else {
                minValue = nums[i];
            }
        }

        return maxDiff;
    }
};
