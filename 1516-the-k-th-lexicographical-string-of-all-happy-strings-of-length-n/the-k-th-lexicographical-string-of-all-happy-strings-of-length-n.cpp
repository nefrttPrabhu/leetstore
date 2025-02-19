
// An-Wen Deng
// class Solution {
// public:
//     string getHappyString(int n, int k) {
//         int sz=3*(1<<(n-1));
//         if (k>sz) return "";
//         auto [q, r]=div(k-1, 1<<(n-1));// k-1
//         string s(n, ' ');
//         s[0]='a'+q;
//         bitset<9> bin(r);
//         array<char, 2> xx[3]={{'b', 'c'}, {'a', 'c'}, {'a', 'b'}};
//         for(int i=n-2; i>=0; i--){
//             char idx=s[n-2-i]-'a';
//             s[n-1-i]=(bin[i])?xx[idx][1]:xx[idx][0];
//         }
//         return s;
//     }
// };


// Tan Hong Bin
// class Solution {
// public:
//     string getHappyString(int n, int k) {
//         // Compute the total number of happy strings of length n: 3 * 2^(n-1)
//         int total = 3 * (1 << (n - 1));

//         // If k exceeds the total count, return an empty string
//         if (k > total) return "";

//         // Compute the quotient (q) and remainder (r):
//         // q determines which group the k-th happy string belongs to ('a', 'b', or 'c').
//         // r determines its index within that group.
//         auto [q, r] = div(k - 1, 1 << (n - 1));

//         // Initialize the result string
//         string result(n, ' ');

//         // Set the first character based on q ('a' for 0, 'b' for 1, 'c' for 2)
//         result[0] = 'a' + q;

//         // Define possible choices for the next character based on the previous one
        
//         array<array<char, 2>, 3> options = {{
//             {'b', 'c'}, // If the previous character is 'a', next can be 'b' or 'c'
//             {'a', 'c'}, // If the previous character is 'b', next can be 'a' or 'c'
//             {'a', 'b'}  // If the previous character is 'c', next can be 'a' or 'b'
//         }};
        

//         // Convert r into a binary representation since it determines the sequence of choices
//         bitset<10> bits(r);

//         // Iterate from i = n-2 because r has n-1 bits (excluding the first character)
//         for (int i = n - 2, index = 1; i >= 0; i--, index++) {
//             // Determine the previous character index (0 for 'a', 1 for 'b', 2 for 'c')
//             int prev = result[index - 1] - 'a';

//             // Select the next character based on the binary representation of r:
//             // If bits[i] is 1, pick options[prev][0]
//             // If bits[i] is 0, pick options[prev][1]
//             result[index] = (bits[i]) ? options[prev][1] : options[prev][0];
//         }

//         return result;
//     }
// };



// class Solution {
// public:
//     void generateHappyStrings(int n, string current, vector<string> &result) {
//         if (current.length() == n) {
//             result.push_back(current);
//             return;
//         }
        
//         for (char ch : {'a', 'b', 'c'}) {
//             if (current.empty() || current.back() != ch) {
//                 generateHappyStrings(n, current + ch, result);
//             }
//         }
//     }

//     string getHappyString(int n, int k) {
//         vector<string> happy;
//         generateHappyStrings(n, "", happy);
        
//         if (k > happy.size()) return "";
//         return happy[k - 1]; // k is 1-based index
//     }
// };


class Solution {
public:
    string ans = "";
    vector<char> v{'a','b','c'};
    bool f(int ind,string &s,int &k){
        if(ind == s.size()){
            k--;
            if(k == 0){
                ans = s;
                return true;
            }
            return false;
        }
        for(auto &ch : v){
            if(ind == 0 || (ind - 1 >= 0 && s[ind - 1] != ch)){
                s[ind] = ch;
                bool dd = f(ind + 1, s, k);
                if(dd) return true;
                s[ind] = '.';
            }
        }
        return false;
    }

    string getHappyString(int n, int k) {
        string s(n, '.');
        f(0, s, k);
        return ans;
    }
};