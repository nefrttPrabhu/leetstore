class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = 0;
        int minSum = 0;
        int currMax = 0;
        int currMin = 0;
        
        for (int num : nums) {
            currMax = max(0, currMax + num);
            currMin = min(0, currMin + num);
            maxSum = max(maxSum, currMax);
            minSum = min(minSum, currMin);
        }
        
        return max(maxSum, abs(minSum));
    }
};
