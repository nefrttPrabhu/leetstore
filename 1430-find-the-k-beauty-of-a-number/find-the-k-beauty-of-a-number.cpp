class Solution {
public:
    int divisorSubstrings(int num, int k) {
        long long copy = num;
        int cnt = 0;
        long long r = 0;
        long long power = 1;

        for (int i = 0; i < k; i++) {
            power *= 10;
        }

        while (copy >= power / 10) {
            r = copy % power;
            if (r != 0 && num % r == 0) {
                cnt++;
            }
            copy /= 10;
        }

        return cnt;
    }
};
