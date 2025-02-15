class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        stringstream ss(s);
        string word;
        int cnt = 0;
        unordered_set<string> seen;

        for(int i = 0; i < pattern.size(); i++) { 
            if (!(ss >> word)) return false;

            seen.insert(word);

            if(mp.find(pattern[i]) != mp.end()) {
                if(word != mp[pattern[i]]) {
                    return false;
                }
            }

            mp[pattern[i]] = word;
        }

        if(mp.size() != seen.size()) return false;
        

        
        // for (auto& pair : mp) {
        //     if (seen.find(pair.second) != seen.end()) {
        //         return false;
        //     }
        //     seen.insert(pair.second);
        // }
        return !(ss >> word);
    } 
};
