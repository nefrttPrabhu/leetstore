class Solution {
public:
    bool helper(char ch) {
        return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
    }

    int countVowelSubstrings(string w) {
        int n = w.size();
        int cnt = 0;

        for (int i = 0; i < n; i++) {
            if (!helper(w[i])) continue;

            map<char, int> freq;

            for (int j = i; j < n && helper(w[j]); j++) {
                freq[w[j]]++;
                if (freq.size() == 5)
                    cnt++;
            }
        }

        return cnt;
    }

};