/*
S1: num is the array ouput having digits not numbers that it the max it can have is digit 9 no number is a two digit in it and the max length of num can only be of 9 digits coz after that the digits will start to repeat
S2: max length of the input string can only be of 8 coz digits can be max of 9  without repeat
   **1 <= pattern.length <= 8** jab ye constraints mai diya ho then no need to put this as one of the conditions
S3: I means step up the next , D means step down the next
S4: can get many of decreasing numbers but have to get the smallest of them all
Eg: DIDIDIDI , IDIDIDID
    214365879, 132547698
*/

class Solution {
public:
    string smallestNumber(string pattern) {
        int n = pattern.size();
        string result = "";
        stack<int> st;
        
        for (int i = 0; i <= n; i++) {
            st.push(i + 1);  
            
            if (i == n || pattern[i] == 'I') {
                while (!st.empty()) {
                    result += to_string(st.top());
                    st.pop();
                }
            }
        }
        return result;
    }
};
