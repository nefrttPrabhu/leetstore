class Solution {
public:
    using ll = long long;
    ll maximumSubarraySum(vector<int>& nums, int k) {
        map<int, int> mp;
        ll sum = 0;
        ll maxSum = 0;
        int i = 0;
        int j = 0;
        int n = nums.size();

        while (j < n) {
            mp[nums[j]]++;
            sum += nums[j];

            if (j - i + 1 > k) {
                mp[nums[i]]--;
                if (mp[nums[i]] == 0) {
                    mp.erase(nums[i]);
                }
                sum -= nums[i];
                i++;
            }

            if (j - i + 1 == k && mp.size() == k) {
                maxSum = max(maxSum, sum);
            }

            j++;
        }

        return maxSum;
    }
};
