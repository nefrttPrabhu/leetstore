class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum = 0;
        int mini = 1e9;
        int i = 0;

        for (int j = 0; j < nums.size(); j++) {
            sum += nums[j];

            while (sum >= target) {
                mini = min(mini, j - i + 1);
                sum -= nums[i];
                i++;
            }
        }

        return (mini == 1e9) ? 0 : mini;
    }
};
