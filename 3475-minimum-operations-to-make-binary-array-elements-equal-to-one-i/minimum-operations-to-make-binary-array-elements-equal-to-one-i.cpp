/*
S1: jis index pe zero usko and uske baad ke do index ki bits flip
S2: 0,1,1,1,0,0 -> 1,0,0,1,0,0 -> 1,1,1,0,0,0 -> 1,1,1,1,1,1
*/
class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ops = 0;

        for (int i = 0; i <= n - 3; i++) {
            if (nums[i] == 0) {
                nums[i] ^= 1;
                nums[i + 1] ^= 1;
                nums[i + 2] ^= 1;
                ops++;
            }
        }

        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) return -1;
        }

        return ops;
    }
};
