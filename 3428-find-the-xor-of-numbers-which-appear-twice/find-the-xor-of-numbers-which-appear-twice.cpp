class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        int n = nums.size();
        int x = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {  
                if (nums[i] == nums[j]) {  
                    x ^= nums[i];  
                    break;  
                }
            }
        }
        return x;
    }
};
