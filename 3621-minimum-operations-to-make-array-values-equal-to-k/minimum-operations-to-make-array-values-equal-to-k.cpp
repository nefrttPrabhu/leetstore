class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        set<int> uniqueElements(nums.begin(), nums.end());
        
        int operations = 0;

        for (int num : uniqueElements) {
            if (num > k) {
                operations++;
            } else if (num < k) {
                return -1;
            }
        }
        return operations;
    }
};