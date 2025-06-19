class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        map<int, int> mp;
        int maxi = INT_MIN;
        for(auto it : nums){
            maxi = max(maxi ,++mp[it]);
        }

        int sum = 0;
        for(auto it : mp){
            if(it.second == maxi){
                sum += it.second;
            }
        }
    return sum;
    }
};