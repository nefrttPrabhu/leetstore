class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> mp;
        int cnt = 0;
        int sum = 0;

        mp[0] = 1; // Handle cases where sum directly equals k

        for(auto n : nums){
            sum += n;
            if (mp.find(sum - k) != mp.end()) {
                cnt += mp[sum - k];
            }
            mp[sum]++;
        }
        return cnt;
    }
};
