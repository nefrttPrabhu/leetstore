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


// class Solution {
// public:
//     string robotWithString(string s) {
//         unordered_map<char, int> mp;
//         string ans = "";
//         stack<int> t;

//         for(auto c: s) mp[c]++;

//         char cur = 'a';

//         for(int i = 0; i < s.size(); i++) {
//             t.push(s[i]);

//             if(--mp[s[i]] == 0) {
//                 mp.erase(s[i]);
//             }

//             while(mp.find(cur) == mp.end() && cur <= 'z') {
//                 cur++;
//             }

//             while(!t.empty() && cur >= t.top()) {
//                 ans += t.top();
//                 t.pop();
//             }

//         }
//         return ans;
//     }
// };






class Solution {
public:
    string robotWithString(string s) {
        string p ="";
        stack<char> t;
        map<char, int> mp;

        for(auto it : s) mp[it]++;

        char curr = 'a';

        for(int i = 0; i < s.size(); i++){
            // while(t.empty() || s[i] > curr){pushing the same character repeatedly so infinite loop
                t.push(s[i]);
            // }

            if(--mp[s[i]] == 0){ //This check happens before decrementing the current s[i] and not mp[curr]
                mp.erase(s[i]);
            }

            // if (!mp.empty()) {
                while (mp.find(curr) == mp.end() && curr <= 'z') {
                    curr++;
                }

            // }


            // while(s[i] == curr){s[i] is constant in this loop, not incrementing i so it's stuck forever
            //     p += s[i];
            // }

            while(!t.empty() && t.top() <= curr){
                p += t.top();
                t.pop();
            }
        }

        return p;
    }
};