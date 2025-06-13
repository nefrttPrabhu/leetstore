class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() - nums[0];
        int ans = right;

        while (left <= right) {
            int mid = (left + right) / 2;
            int count = 0;

            for (int i = 1; i < nums.size(); ) {
                if (nums[i] - nums[i - 1] <= mid) {
                    count++;
                    i += 2;
                } 
                else {
                    i++;
                }
            }

            if (count >= p) {
                ans = mid;
                right = mid - 1;
            }
            else {
                left = mid + 1;
            }
        }

        return ans;
    }
};
