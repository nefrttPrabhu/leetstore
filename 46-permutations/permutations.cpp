class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> result;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        result.push_back(nums);

        while (true) {
            int i = n - 2;
            while (i >= 0 && nums[i] >= nums[i + 1]) i--;
            if (i < 0) break;

            int j = n - 1;
            while (nums[j] <= nums[i]) j--;
            swap(nums[i], nums[j]);

            int left = i + 1, right = n - 1;
            while (left < right) {
                swap(nums[left], nums[right]);
                left++;
                right--;
            }

            result.push_back(nums);
        }

        return result;
    }
};
