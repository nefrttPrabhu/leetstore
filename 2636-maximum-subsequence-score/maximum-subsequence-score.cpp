// class Solution {
// public:
//     long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
//         int n = nums1.size();
//         vector<pair<int, int>> pairs;

//         // Step 1: Pair nums2[i] with nums1[i] and sort by nums2[i] in descending order
//         for (int i = 0; i < n; i++) {
//             pairs.emplace_back(nums2[i], nums1[i]);
//         }
//         sort(pairs.rbegin(), pairs.rend()); // Sort by nums2[i] descending

//         priority_queue<int, vector<int>, greater<int>> minHeap;
//         long long sum = 0, maxScore = 0;

//         // Step 2: Iterate through sorted nums2 while maintaining a heap of k elements from nums1
//         for (int i = 0; i < n; i++) {
//             int num2 = pairs[i].first;
//             int num1 = pairs[i].second;

//             sum += num1;
//             minHeap.push(num1);

//             if (minHeap.size() > k) {
//                 sum -= minHeap.top();
//                 minHeap.pop();
//             }

//             if (minHeap.size() == k) {
//                 maxScore = max(maxScore, sum * num2);
//             }
//         }

//         return maxScore;
//     }
// };


class Solution {
public:
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<pair<int, int>> nums;
        for (int i = 0; i < nums1.size(); i++) {
            nums.push_back({nums1[i], nums2[i]});
        }

        sort(nums.begin(), nums.end(), [](auto &a, auto &b) {
            return a.second > b.second; 
        });

        priority_queue<int, vector<int>, greater<>> pq;
        long long sum = 0;
        long long ans = 0;

        for (auto & p:nums) {
            pq.push(p.first);
            sum += p.first;

            if (pq.size()>k) {
                sum-=pq.top();
                pq.pop();
            }
            if (pq.size() == k) {
                ans = max(ans, sum*(long long)p.second);
            }
        }
        return ans;
    }
};