class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length()) return false;

        map<char, char> mp;
        map<char, char> mpp;

        for (int i = 0; i < s.length(); ++i) {
            char c1 = s[i];
            char c2 = t[i];

            if (mp.count(c1)) {
                if (mp[c1] != c2)
                    return false;
            } 
            else {
                mp[c1] = c2;
            }

            if (mpp.count(c2)) {
                if (mpp[c2] != c1)
                    return false;
            } 
            else {
                mpp[c2] = c1;
            }
        }

        return true;
    }
};
