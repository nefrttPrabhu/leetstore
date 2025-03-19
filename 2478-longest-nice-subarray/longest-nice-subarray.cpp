class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l = 0;
        int ans = 0;
        int mL = 0;
        
        for (int r = 0; r < nums.size(); ++r) {
            while ((ans & nums[r]) != 0) {
                ans ^= nums[l];
                l++;
            }
            
            ans |= nums[r];
            mL = max(mL, r - l + 1);
        }
        
        return mL;
    }
};
