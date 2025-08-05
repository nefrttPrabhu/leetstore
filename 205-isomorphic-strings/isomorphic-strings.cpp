class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char> map1,map2;
        for(int i = 0; i < s.size(); i++){
            if(map1.find(t[i]) != map1.end() && map1[t[i]] != s[i]){
                return false;
            }
            if(map2.find(s[i]) != map2.end() && map2[s[i]] != t[i]){
                return false;
            }
            else{
                map1[t[i]] = s[i];
                map2[s[i]] = t[i];
            }
        }
        return  true;
    }
};