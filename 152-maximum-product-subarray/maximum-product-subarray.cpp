class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int maxi = INT_MIN;
        int ans = 1;
        map<int, int> mp;

        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] > 0) {
                ans *= nums[j];
                maxi = max(maxi, ans);
            }
            else if (nums[j] < 0) {
                ans *= nums[j];
                maxi = max(maxi, ans);
            }
            else if (nums[j] == 0) {
                mp[0]++;
                maxi = max(maxi, 0);
                ans = 1; // reset after zero
            }
        }

        ans = 1;
        for (int j = nums.size() - 1; j >= 0; j--) {
            if (nums[j] > 0) {
                ans *= nums[j];
                maxi = max(maxi, ans);
            }
            else if (nums[j] < 0) {
                ans *= nums[j];
                maxi = max(maxi, ans);
            }
            else if (nums[j] == 0) {
                maxi = max(maxi, 0);
                ans = 1;
            }
        }

        return maxi;
    }
};
