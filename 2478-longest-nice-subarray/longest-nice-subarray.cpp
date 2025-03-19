/*
concept bitmasking jaise jaise ek number ko hum and kar rhe and result mai all 0 aa rhe means uss number ke ones jo hi not contributing, so hume ek number ke 1's ka he kaam hi toh fir and jo do mai common 1's hi vo overlap kar jayenge vo apne aap he count ho jayenge then jaise 3(0011) or 8(1000)  AND=0 OR=1011 means next number jo hum check karenge usmai 8 ki set bits he contri kar skti hi and 3 ki bhi set bits but ye toh repeated task hoga iss acha if 3 and 8 agar dono final hi toh unki common set bits ko lo and next se sath check karlo saving TC
*/
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
