class Solution {
public:
    int maxDifference(string s) {
        map<char, int> mp;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (char it : s) {
            mp[it]++;
        }

        for (auto it : mp) {
            if (it.second % 2) {
                maxi = max(maxi, it.second);
            } 
            else {
                mini = min(mini, it.second);
            }
        }

        if (maxi == INT_MIN || mini == INT_MAX)
            return -1;

        return maxi - mini;
    }
};
