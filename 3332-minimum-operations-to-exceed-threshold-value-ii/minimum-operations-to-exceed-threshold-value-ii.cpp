class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq(nums.begin(), nums.end());

        int c = 0;

        while (pq.top() < k && pq.size() > 1) {
            long long smallest = pq.top();
            pq.pop();

            long long smaller = pq.top();
            pq.pop();

            pq.push(smallest * 2 + smaller);

            c++;
        }

        return (pq.top() >= k) ? c : -1; 
    }
};
