class Solution {
public:
    bool wordPattern(string pattern, string s) {
        unordered_map<char, string> mp;
        stringstream ss(s);
        string word;
        int cnt = 0;
        unordered_set<string> seen;

        for(int i = 0; i < pattern.size(); i++) { 
            if (!(ss >> word)) 
                return false;

            seen.insert(word);

            if(mp.find(pattern[i]) != mp.end()) { //agar a,b ya koi bhi present hi toh 
                if(word != mp[pattern[i]]) { //check karo ki uss present a,b ka jo mapped word hi vo he kya abhi aya hi ki nhi agr nhi then false return kardo 
                    return false;
                }
            }
            //agar nhi tab fir uss a,b ya koi ko bhi map kardo coz vo 1st occurance hi but ismai hoga ye ki maanlo a mai phele he dog map ho chuka hi ab c aya uspe bhi dog map ho jayega per vo uper wale if mai nhi jayega coz c ki 1st occurance hogi vo toh c bhi dog se map ho jayega yahi cheez set handle karega coz fir hoga ye map mai toh c dog se map ho jayega toh map ka size 3 ho jayega per set ka size 2 he rahega coz dog phele a e sath map ho chuka hi toh vo unique nhi rha toh set mai nhi jayega 
            mp[pattern[i]] = word;
        }
        //idhar to check whether there are extra words left in the string s after processing all characters in pattern and set ka size and map ka size unique mapping ke liye karlenge
        return !(ss >> word) && mp.size() == seen.size();
    } 
};
