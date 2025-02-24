class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        int pos = 0;
        int neg = 1;
        vector<int> temp(n, 0);

        for(int i = 0; i < n; i++){
            if(nums[i] > 0){
                temp[pos] = nums[i];
                pos += 2;
            }

            else{
                temp[neg] = nums[i];
                neg += 2;
            }
        }
        return temp;
    }
};