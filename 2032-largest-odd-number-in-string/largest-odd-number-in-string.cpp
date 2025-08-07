class Solution {
public:
    string largestOddNumber(string num) {
        while (!num.empty()) {
            char last = num.back();
            if ((last - '0') % 2 == 1) {
                return num; 
            }
            num.pop_back(); 
        }
        return "";
    }
};
