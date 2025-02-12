class Solution {
public:
    string clearDigits(string s) {
        string a = "";

        for(int i = 0; i < s.size(); i++) {
            if(isdigit(s[i])) {
                a.pop_back();
                continue;
            } 
            a += s[i];
        }
        return a;
    }
};