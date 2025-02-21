class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0;
        int right = 0;
        int cnt = 0;

        for(right = 0; right < nums.size(); right++) {
            while(nums[right] == 0 && k == 0) {
                if(nums[left] == 0) k++;
                left++;
            }

            if(nums[right] == 0) k--;

            cnt = max(cnt, right - left + 1);
        }
        return cnt;
    }
};