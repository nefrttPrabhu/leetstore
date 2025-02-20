class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int size = nums.size();
        vector<int> result(size, 0);
        int positiveIndex = 0;
        int negativeIndex = 1;
        
        for(int i = 0; i < size; i++){
            if(nums[i] < 0){
                result[negativeIndex] = nums[i];
                negativeIndex += 2;
            } 
            
            else {
                result[positiveIndex] = nums[i];
                positiveIndex += 2;
            }
        }

        return result;
    }
};
