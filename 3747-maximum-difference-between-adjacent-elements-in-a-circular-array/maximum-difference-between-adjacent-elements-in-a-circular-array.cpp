class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int n = nums.size();
        vector<int> v(2 * n, 0);
        int maxi = INT_MIN;

        for (int i = 0; i < n; i++) {
            v[i] = nums[i];
            v[i + n] = nums[i];
        }

        for (int i = 0; i < v.size() - 1; i++) {
            maxi = max(maxi, abs(v[i] - v[(i + 1)])); 
        }

        return maxi;
    }
};
