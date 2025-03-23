class Solution {
public:
    vector<string> stringMatching(vector<string>& words) {
        unordered_set<string> resultSet;
        int n = words.size();
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (i != j && words[j].find(words[i]) != string::npos) {
                    resultSet.insert(words[i]);
                }
            }
        }
        
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};

