class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l = nums.size();
        int c = 0;
        int maxi = 0;

        for(int i = 0;i < l; i++){
            if(nums[i] == 1){
                c++;
            }

            else{
                c = 0;
            }
                maxi = max(maxi,c);
        }
        return maxi;
    }
};