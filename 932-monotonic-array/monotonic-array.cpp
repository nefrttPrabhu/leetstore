class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if(nums.size() == 1) return true;

        int a = nums[0];
        int b = nums[nums.size() - 1];

        if(a <= b){ //increasing 
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i + 1] < nums[i]) {
                    return false;
                }
            }
        }
        else{ //decreasing
            for(int i = 0; i < nums.size() - 1; i++){
                if(nums[i + 1] > nums[i]) {
                    return false;
                }
            }
        }
        return true;
    }
};