class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = nums.size();
        int c = 0;
        int maxi = 0;
        for(int i = 0;i < l; i++){
            if(nums[i] == 1){
                c++;
                maxi = max(maxi,c);
            }
            else{
                c = 0;
            }
        }
        return max(maxi,c);
    }
};