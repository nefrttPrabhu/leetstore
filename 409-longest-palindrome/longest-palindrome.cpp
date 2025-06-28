class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char, int> mp;

        for (auto it : s) {
            mp[it]++;
        }

        int sum = 0;
        int oc = 0;

        for (auto it : mp) {
            if (it.second % 2 == 0) {
                sum += it.second;
            } 
            else {
                sum += it.second - 1;
                oc = 1;
            }
        }

        return sum + oc;
    }
};
