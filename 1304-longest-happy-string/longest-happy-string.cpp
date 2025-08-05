class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq; //max heap
        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});
        
        string ans = "";

        while (!pq.empty()) {
            auto [cnt, ch1] = pq.top(); 
            pq.pop();
            
            int len = ans.size();
            if (len >= 2 && ans[len - 1] == ch1 && ans[len - 2] == ch1) {
                if (pq.empty()) break;

                auto [cntt, ch2] = pq.top(); pq.pop();
                ans += ch2;
                cntt--;

                if (cntt > 0) pq.push({cntt, ch2});
                pq.push({cnt, ch1});
            } 
            else {
                ans += ch1;
                cnt--;
                if (cnt > 0) pq.push({cnt, ch1});
            }
        }
        return ans;
    }
};
