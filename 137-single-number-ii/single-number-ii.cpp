class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (int n : nums) {
            mp[n]++;
        }
        
        for (auto& [key, value] : mp) {
            if (value == 1) {
                return key;
            }
        }
        
        return -1; 
    }
};
