class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int z = 0;
        
        for(int nz = 0;nz < n; nz++){
            if(nums[nz] != 0){
                int temp = nums[nz];
                nums[nz] = nums[z];
                nums[z] = temp;
                z++;
            }
        }
    }
};