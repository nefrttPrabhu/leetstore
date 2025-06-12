class Solution {
public:
    string longestPalindrome(string s) {
        int start = 0, maxLen = 0;
        for(int i = 0; i < s.size(); i++) {
            expand(s, i, i, start, maxLen);  
            expand(s, i, i+1, start, maxLen); 
        }
        return s.substr(start, maxLen);
    }

    void expand(const string &s, int l, int r, int &start, int &maxLen) {
        while(l >= 0 && r < s.size() && s[l] == s[r]) {
            l--;
            r++;
        }
        int len = r - l - 1;
        if(len > maxLen) {
            start = l + 1;
            maxLen = len;
        }
    }
};
