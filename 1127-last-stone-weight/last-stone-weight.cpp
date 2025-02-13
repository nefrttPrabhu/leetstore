// class Solution {
// public:
//     int lastStoneWeight(vector<int>& stones) {
//         priority_queue<int> pq(stones.begin(), stones.end()); //insert without using for loop for each of the stone in given vector

//         while (pq.size() > 1) {
//             int stone1 = pq.top();
//             pq.pop();
            
//             int stone2 = pq.top(); 
//             pq.pop();
            
//             if (stone1 != stone2) {
//                 pq.push(stone1 - stone2);
//             }
//         }

//         return pq.empty() ? 0 : pq.top();
//     }
// };


class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            
            int stone1 = stones.back(); 
            stones.pop_back();

            int stone2 = stones.back(); 
            stones.pop_back();

            if (stone1 != stone2) {
                stones.push_back(stone1 - stone2);
            }
        }
        return stones.empty() ? 0 : stones[0];
    }
};