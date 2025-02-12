class Solution {
public:
    int singleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n = nums.size();

        for(int i = 1; i < n - 1; i += 3){
            if(nums[i] != nums[i-1]){
                return nums[i - 1]; //beech mai koi 
            }
        }
        return nums[n - 1]; //if no beech ka then automatically last one
    }
};