class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int i = 0, j = 0;
        int maxi = 0;

        while (j < nums.size()) {
            if (nums[j]) {
                maxi = max(maxi, j - i + 1);
                j++;
            }
            else if (k > 0) {
                k--;
                maxi = max(maxi, j - i + 1);
                j++;
            }
            else {
                while (!k) {
                    if (!nums[i]) {
                        k++;
                    }
                    i++;
                }
            }
        }

        return maxi;
    }
};
