class Solution {
public:
    long long repairCars(vector<int>& ranks, int cars) {
        long long left = 1, right = 1LL * (*min_element(ranks.begin(), ranks.end())) * cars * cars;
        long long answer = right;
        
        while (left <= right) {
            long long mid = left + (right - left) / 2;
            long long repaired = 0;
            
            for (int r : ranks) {
                repaired += sqrt(mid / r);
                if (repaired >= cars) break;
            }
            
            if (repaired >= cars) {
                answer = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        
        return answer;
    }
};
