class Solution {
public:
    long long distributeCandies(int n, int limit) {
        auto combinations = [](int total, int groups) -> long long {
            if (total < 0) return 0;
            if (groups == 1) return 1;
            
            long long result = 1;
            int k = groups - 1;
            int n_val = total + k;
            
            if (k > n_val - k) k = n_val - k;
            
            for (int i = 0; i < k; i++) {
                result = result * (n_val - i) / (i + 1);
            }
            
            return result;
        };
        
        long long total = combinations(n, 3);
        long long subtract1 = 3 * combinations(n - (limit + 1), 3);
        long long add2 = 3 * combinations(n - 2 * (limit + 1), 3);
        long long subtract3 = combinations(n - 3 * (limit + 1), 3);
        
        return total - subtract1 + add2 - subtract3;
    }
};