// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         if (s.length() != t.length()) 
//             return false;
        
//         unordered_map<char, char> st;
//         unordered_map<char, char> ts;
        
//         for (int i = 0; i < s.length(); i++) {
//             char sc = s[i];
//             char tc = t[i];

//             if (st.count(sc) && st[sc] != tc) 
//                 return false;

//             if (ts.count(tc) && ts[tc] != sc) 
//                 return false;

//             st[sc] = tc;
//             ts[tc] = sc;
//         }
        
//         return true;
//     }
// };

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        int sn = s.size();
        int tn = t.size();
        if (sn != tn){
            return false;
        }
        unordered_map<char, char> mp;
        unordered_set<char> used;
        for(int i = 0; i < sn; i++){
            if(mp.find(s[i]) == mp.end()){
                if (used.find(t[i]) != used.end()) 
                    return false; 

                mp[s[i]] = t[i];
                used.insert(t[i]);
            }

            else if(mp[s[i]] == t[i]){
                continue;
            }

            else{
                return false;
            }
        }
        return true;
    }
};
