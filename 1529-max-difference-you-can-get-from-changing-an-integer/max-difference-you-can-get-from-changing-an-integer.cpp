class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxS = s, minS = s;

        for (char c : s) {
            if (c != '9') {
                replace(maxS.begin(), maxS.end(), c, '9');
                break;
            }
        }

        if (s[0] != '1') {
            replace(minS.begin(), minS.end(), s[0], '1');
        } else {
            for (int i = 1; i < s.size(); i++) {
                if (s[i] != '0' && s[i] != '1') {
                    replace(minS.begin(), minS.end(), s[i], '0');
                    break;
                }
            }
        }

        return stoi(maxS) - stoi(minS);
    }
};
