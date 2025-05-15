class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int len = 1, prev = groups[0];
        
        for (int i = 1, j = 1; i < n; i++) {
            while (i < n && prev == groups[i])
                i++;
            if (i < n) {
                words[j++] = words[i];
                len++;
                prev = groups[i];
            }
        }
        
        words.resize(len);
        return words;
    }
};
