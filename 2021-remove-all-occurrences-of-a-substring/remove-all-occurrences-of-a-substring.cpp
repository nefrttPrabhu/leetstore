// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         while (s.find(part) != string::npos) {
//             s.erase(s.find(part), part.length());
//         }
//         return s;
//     }
// };



// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         while(s.length()>0 && s.length()>s.find(part)){
//            s.erase(s.find(part),part.length());
//         }
//         return s;
//     }
// };



// class Solution {
// public:
//     bool check(stack<char>& st, string& part, int n){
//         stack<char> temp = st;

//         for(int i = n - 1; i >= 0; i--){
//             if(temp.top() != part[i]){
//                 return false;
//             }

//             temp.pop();
//         }

//         return true;
//     }

//     string removeOccurrences(string s, string part) {
//         stack<char> st;
//         int m = s.length();
//         int n = part.length();

//         for(int i = 0; i < m; i++){
//             st.push(s[i]);

//             if(st.size() >= n && check(st, part, n) == true) {
//                 for(int j = 0; j < n; j++){
//                     st.pop();
//                 }
//             }
//         }

//         string res = "";
//         while(!st.empty()){
//             res.push_back(st.top());
//             st.pop();
//         }

//         reverse(res.begin(), res.end());
//         return res;
    
//     //     string res = "";
//     //     int n = part.length();

//     //     for(char& ch : s){
//     //         res.push_back(ch);

//     //         if(res.length() >= n && res.substr(res.length() - n) == part){
//     //             res.erase(res.length() - n);
//     //         }
//     //     }

//     //     return res;
//     }
// };



// OPTIMIZED APPROACH
class Solution {
public:
    string removeOccurrences(string s, string part) {
        string ans;
        int partSize = part.size();

        for (char c : s) {
            ans.push_back(c);

            // Check if `part` is formed at the end
            if (ans.size() >= partSize && ans.substr(ans.size() - partSize) == part) {
                ans.resize(ans.size() - partSize);  // Remove `part`
            }
        }
        return ans;
    }
};



// class Solution {
// public:
//     string removeOccurrences(string s, string part) {
//         string ans = "";
//         int partSize = part.size();
//         int j = 0;

//         for(int i = 0; i < s.size(); i++) {
//             ans += s[i];
//             j++;
//             if(j >= partSize && s.substr(j - partSize, partSize) == part) {
//                 ans.erase(j - partSize, partSize);
//                 j -= partSize;
//             }
//         }
//         return ans;
//     }
// };