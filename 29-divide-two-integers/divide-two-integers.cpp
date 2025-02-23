class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }

        bool neg = (dividend < 0) ^ (divisor < 0);
        
        long long a = abs((long long)dividend);
        long long b = abs((long long)divisor);
        long long quo = 0;

        while (a >= b) {
            long long temp = b;
            long long m = 1;
            
            while (a >= temp + temp) {
                temp += temp; 
                m += m; 
            }
            
            a -= temp;
            quo += m;
        }

        return neg ? -quo : quo;
    }
};
