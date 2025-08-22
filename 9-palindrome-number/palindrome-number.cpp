class Solution {
public:
    bool isPalindrome(int x) {
        long long sum = 0;
        long long n = x;

        if(x < 0){
            return false;
        }

        else{
            long long r = 0;

            while(x != 0){
                r = x % 10;
                sum = sum * 10 + r;
                x = x / 10;
            }
        }

        if(sum == n) return true;
        return false;
    }
};