// class Solution {
// public:
//     string robotWithString(string s) {
//         map<char, int> mp;
        
//         stack<char> st;

//         string t = "";
//         string p = "";

//         for(int i = s.size() - 1; i >= 0; i--) {
//             st.push(s[i]);
//         }

//         for(auto ch : s) {
//             mp[ch]++;
//         }

//         char curr = 'a';

//         while(!st.empty()) {
//             while(mp.find(curr) == mp.end()) {
//                 curr++;
//             }

//             char top = st.top(); 
//             st.pop();

//             if(top == curr) {
//                 p += top;
//                 mp[top]--;
//                 if(mp[top] == 0){
//                     mp.erase(top);
//                 }
//             } 
//             else {
//                 t += top;
//                 mp[top]--;
//                 if(mp[top] == 0) {
//                     mp.erase(top);
//                 }
//             }
//         }

//         for(char ch : t) {
//             p += ch;
//         }

//         return p;
//     }
// };


class Solution {
public:
    string robotWithString(string s) {
        unordered_map<char, int> mp;
        string ans = "";
        stack<int> t;

        for(auto c: s) mp[c]++;

        char cur = 'a';

        for(int i = 0; i < s.size(); i++) {
            t.push(s[i]);

            if(--mp[s[i]] == 0) {
                mp.erase(s[i]);
            }

            while(mp.find(cur) == mp.end() && cur <= 'z') {
                cur++;
            }

            while(!t.empty() && cur >= t.top()) {
                ans += t.top();
                t.pop();
            }

        }
        return ans;
    }
};