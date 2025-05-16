class Solution {
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1), parent(n, -1);
        int maxLen = 1, maxIndex = 0;

        auto hammingDistance = [](const string& a, const string& b) {
            if (a.length() != b.length()) return -1;
            int distance = 0;
            for (size_t i = 0; i < a.length(); ++i) {
                if (a[i] != b[i]) distance++;
            }
            return distance;
        };

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                if (groups[i] != groups[j] && words[i].length() == words[j].length() &&
                    hammingDistance(words[i], words[j]) == 1) {
                    if (dp[j] + 1 > dp[i]) {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
            if (dp[i] > maxLen) {
                maxLen = dp[i];
                maxIndex = i;
            }
        }

        vector<string> result;
        for (int i = maxIndex; i != -1; i = parent[i]) {
            result.push_back(words[i]);
        }
        reverse(result.begin(), result.end());
        return result;
    }
};