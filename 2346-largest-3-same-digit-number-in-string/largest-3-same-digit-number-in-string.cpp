class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        for (char d = '9'; d >= '0'; d--) {
            for (int j = 0; j <= n - 3; j++) {
                if (num[j] == d && num[j + 1] == d && num[j + 2] == d) {
                    return num.substr(j, 3);
                }
            }
        }
        return "";
    }
};
