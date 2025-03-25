class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> n(numbers);
        int i = 0;
        int j = n.size() - 1;

        while (i <= j) {
            int sum = n[i] + n[j];
            if (sum == target) {
                return {i + 1, j + 1};
            }
            if (sum < target) {
                i++;
            } else {
                j--;
            }
        }
        return {};
    }
};
