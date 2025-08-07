class Solution {
public:
    string shortestPalindrome(string s) {
        string rev = s;
        reverse(rev.begin(), rev.end());
        string ss = s + "#" + rev;
        vector<int> lps(ss.size(), 0);

        for (int i = 1; i < ss.size(); i++) {
            int len = lps[i - 1];
            while (len > 0 && ss[i] != ss[len]) {
                len = lps[len - 1];
            }
            if (ss[i] == ss[len]) {
                len++;
            }
            lps[i] = len;
        }

        string nn = rev.substr(0, s.size() - lps.back());
        return nn + s;
    }
};
