class Solution {
public:
    void generateSubsets(vector<int>& nums, int index, vector<int>& current, vector<vector<int>>& result){
        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        generateSubsets(nums, index + 1, current, result); // include 

        current.pop_back();
        generateSubsets(nums, index + 1, current, result);//exclude
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> result;
        vector<int> current;
        generateSubsets(nums, 0, current, result);
        return result;
    }

};