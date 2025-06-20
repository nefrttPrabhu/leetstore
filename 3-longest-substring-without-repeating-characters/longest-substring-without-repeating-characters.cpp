class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> p;
        int i = 0, j = 0;
        int maxi = 0;
        string ss = "";

        while (j < s.size()) {
            if (p[s[j]] == 0) {
                ss += s[j];
                p[s[j]]++;
                j++;
                maxi = max(maxi, j - i);
            } else {
                p[s[i]]--;
                ss.erase(0, 1);
                i++;
            }
        }

        return maxi;
    }
};
