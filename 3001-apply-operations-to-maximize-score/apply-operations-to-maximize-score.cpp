#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        
        // Step 1: Compute the prime score for each number in nums
        vector<int> primeScores(n);
        int max_num = *max_element(nums.begin(), nums.end());
        vector<int> spf(max_num + 1); // smallest prime factor
        iota(spf.begin(), spf.end(), 0);
        
        // Sieve of Eratosthenes to compute SPF
        for (int i = 2; i * i <= max_num; ++i) {
            if (spf[i] == i) {
                for (int j = i * i; j <= max_num; j += i) {
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
        
        // Compute prime score for each number in nums
        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            int score = 0;
            if (x == 1) {
                primeScores[i] = 0;
                continue;
            }
            int last_prime = 0;
            while (x > 1) {
                int p = spf[x];
                if (p != last_prime) {
                    score++;
                    last_prime = p;
                }
                x /= p;
            }
            primeScores[i] = score;
        }
        
        // Step 2: Find the next greater or equal prime score elements to the left and right
        vector<int> left(n, -1);
        vector<int> right(n, n);
        stack<int> st;
        
        // Left pass: find the next greater or equal to the left
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && primeScores[st.top()] < primeScores[i]) {
                st.pop();
            }
            if (!st.empty()) {
                left[i] = st.top();
            }
            st.push(i);
        }
        
        // Clear the stack for the right pass
        while (!st.empty()) st.pop();
        
        // Right pass: find the next greater or equal to the right
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && primeScores[st.top()] <= primeScores[i]) {
                st.pop();
            }
            if (!st.empty()) {
                right[i] = st.top();
            }
            st.push(i);
        }
        
        // Step 3: Calculate the number of valid subarrays for each element and use a max-heap
        priority_queue<pair<int, long long>> pq; // (value, count)
        for (int i = 0; i < n; ++i) {
            long long l = i - left[i];
            long long r = right[i] - i;
            long long count = l * r;
            pq.push({nums[i], count});
        }
        
        long long result = 1;
        int remaining_k = k;
        while (remaining_k > 0 && !pq.empty()) {
            auto [val, cnt] = pq.top();
            pq.pop();
            long long take = min((long long)remaining_k, cnt);
            result = (result * modPow(val, take, MOD)) % MOD;
            remaining_k -= take;
        }
        
        return result;
    }
    
private:
    long long modPow(long long x, long long n, int mod) {
        long long res = 1;
        while (n > 0) {
            if (n % 2 == 1) {
                res = (res * x) % mod;
            }
            x = (x * x) % mod;
            n /= 2;
        }
        return res;
    }
};