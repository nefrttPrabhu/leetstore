class Solution {
public:
    bool wordPattern(string pattern, string s) {
        string word;
        unordered_set<string> seen;
        stringstream ss(s);
        int n = pattern.size();
        unordered_map<char, string>mp;

        for(int i = 0; i < n; i++){
            if(!(ss >> word)){
                return false;
            }
            seen.insert(word);

            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != word){
                    return false;
                }
            }
            mp[pattern[i]] = word;
        }
        return !(ss >> word) && mp.size() == seen.size();
    }
};