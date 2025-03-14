class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int l = nums.size();
        int a = 0;
        int j = 0;
        while(j < l){
            if(nums[j] != val){
                nums[a] = nums[j];
                a++;
                j++;
            }
            else{
                j++;;
            }
        }
        return a;
    }
};