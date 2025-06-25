class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        int n = s.size();
        vector<string> v;

        while (s.size() % k != 0) {
            s += fill;
        }

        for (int i = 0; i < s.size(); i += k) {
            v.push_back(s.substr(i, k));
        }

        return v;
    }
};
