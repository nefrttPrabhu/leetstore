// class Solution {
// public:
//     int divide(int dividend, int divisor) {
//         if (dividend == INT_MIN && divisor == -1) {
//             return INT_MAX;
//         }

//         bool neg = (dividend < 0) ^ (divisor < 0);
        
//         long long a = abs((long long)dividend);
//         long long b = abs((long long)divisor);
//         long long quo = 0;

//         while (a >= b) {
//             long long temp = b;
//             long long m = 1;
            
//             while (a >= temp + temp) {
//                 temp += temp; 
//                 m += m; 
//             }
            
//             a -= temp;
//             quo += m;
//         }

//         return neg ? -quo : quo;
//     }
// };




class Solution {
public:
    int divide(int dividend, int divisor) {
        int a = dividend;
        int b = divisor;
        if (b == 1) {
            return a;
        }
        if (a == INT_MIN && b == -1) {
            return INT_MAX;
        }
        bool sign = (a > 0 && b > 0) || (a < 0 && b < 0);
        a = a > 0 ? -a : a;
        b = b > 0 ? -b : b;
        int ans = 0;
        while (a <= b) {
            int x = b;
            int cnt = 1;
            while (x >= (INT_MIN >> 1) && a <= (x << 1)) {
                x <<= 1;
                cnt <<= 1;
            }
            ans += cnt;
            a -= x;
        }
        return sign ? ans : -ans;
    }
};