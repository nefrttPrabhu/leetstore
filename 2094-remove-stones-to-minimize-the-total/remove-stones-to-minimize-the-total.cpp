class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        int sum = 0;
        priority_queue<int> pq;
        
        for(int i = 0; i < n; i++){
            sum += piles[i];
            pq.push(piles[i]);
        }

        for(int i = 0; i < k; i++){
            int element = pq.top();
            pq.pop();
            int remove = element / 2;
            element -= remove;
            sum = sum - remove;

            pq.push(element);
        }
        return sum;
    }
};