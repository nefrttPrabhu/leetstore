class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        stringstream ss(s);
        string word;
        int cnt = 0;

        for(int i = 0; i < pattern.size(); i++) { 
            if (!(ss >> word)) return false;

            if(mp.find(pattern[i]) != mp.end()) {
                if(word != mp[pattern[i]]) {
                    return false;
                }
            }

            mp[pattern[i]] = word;
        }
        

        unordered_set<string> seen;
        for (auto& pair : mp) {
            if (seen.find(pair.second) != seen.end()) {
                return false;
            }
            seen.insert(pair.second);
        }
        return !(ss >> word);
    } 
};
