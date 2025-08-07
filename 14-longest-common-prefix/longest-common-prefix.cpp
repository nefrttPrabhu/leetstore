class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) return "";

        int mini = INT_MAX;
        for (auto it : strs) {
            mini = min(mini, (int)it.size());
        }

        string s = "";

        for (int i = 0; i < mini; i++) {
            char ch = strs[0][i];  
            for (int j = 1; j < strs.size(); j++) {
                if (strs[j][i] != ch) {
                    return s; 
                }
            }
            s += ch;  
        }

        return s;
    }
};
