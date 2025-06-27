class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        if(!nums.size()) return 0;
        int c = 1;
        int maxi = 0;
        for(int i = 0; i < nums.size() - 1; i++){
            if(nums[i] == nums[i + 1]) continue;
            if(nums[i] + 1 == nums[i + 1]){
                c++;
            }
            else{
                maxi = max(maxi, c);
                c = 1;
            }
        }
        maxi = max(maxi, c); 
        return maxi;
    }
};