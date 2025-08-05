class Solution {
public:
    using p = pair<int, int>;
    
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        priority_queue<p> pqmax;
        priority_queue<p, vector<p>, greater<p>> pqmin;

        for(int i = 0; i < nums.size(); i++) {
            pqmax.push({nums[i], i}); 
        }

        // Transfer top k elements from max-heap to min-heap
        int count = 0;
        while(count < k && !pqmax.empty()) {
            p top = pqmax.top(); pqmax.pop();
            pqmin.push({top.second, top.first});
            count++;
        }

        vector<int> ans;
        while(!pqmin.empty()) {
            ans.push_back(pqmin.top().second);
            pqmin.pop();
        }

        return ans;
    }
};
