class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int size = nums.size();
        if(!size){
            return 0;
        }

        int j = 0;
        for(int i = 1; i < size; i++){
            if(nums[i] != nums[j]){
                j++;
                nums[j] = nums[i];
            }
        }
        return j + 1;
    }
};