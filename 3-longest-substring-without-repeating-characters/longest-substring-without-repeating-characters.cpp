class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> mp;
        int i = 0, j = 0;
        int maxi = 0;

        while (j < s.size()) {
            if (mp.find(s[j]) == mp.end()) {
                mp[s[j]]++;
                maxi = max(maxi, (int)mp.size());
                j++;
            } else {
                while (mp.find(s[j]) != mp.end()) {
                    mp[s[i]]--;
                    if (mp[s[i]] == 0) {
                        mp.erase(s[i]);
                    }
                    i++;
                }
            }  
        }

        return maxi;
    }
};
