// class Solution {
// public:
//     double myPow(double x, int n) {
//         if (n == 0) {
//             return 1.0;
//         }

//         long long exp = n; 
//         if (exp < 0) {
//             x = 1 / x;
//             exp = -exp;
//         }

//         double result = 1.0;
//         while (exp > 0) {
//             if (exp % 2 == 1) { 
//                 result *= x;
//             }
//             x *= x;
//             exp /= 2; 
//         }
    
//         return result;
//     }
// };



class Solution {
    public:
    double myPow(double x, int n) {
        long long power = n;
        if (power < 0) {
            power = -power;
            x = 1 / x;
        }

        double result = 1.0;
        while (power > 0) {
            if (power & 1) result *= x;  // If the last bit is 1, multiply result by x
            x *= x;  // Square x
            power >>= 1;  // Right shift n (Divide by 2)
        }
        return result;
    }
};