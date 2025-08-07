class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.size();

        for (int d = 9; d >= 0; d--) {
            for (int j = 0; j <= n - 3; j++) {
                if (num[j] - '0' == d && num[j] == num[j + 1] && num[j] == num[j + 2]) {
                    return num.substr(j, 3);
                }
            }
        }
        return "";
    }
};
