class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int sum = 0;
        for(int i = 0; i < nums.size(); i++){
            sum = 0;
            sum += nums[i];
            for(int j = i + 1; j < nums.size(); j++){
                if(j != i){
                    if(sum + nums[j] == target){
                        return {i, j};
                    }
                }
            }
        }
        return {};
    }
};