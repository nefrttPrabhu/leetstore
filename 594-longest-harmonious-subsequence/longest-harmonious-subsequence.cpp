class Solution {
public:
    int findLHS(vector<int>& nums) {
        int cnt = 0;
        map<int, int> mp;

        for(auto it : nums) mp[it]++; 
        if(mp.size() == 1) return cnt;

        for(auto it : mp){
            if(mp.find(it.first + 1) != mp.end()){
                cnt = max(cnt, it.second + mp[it.first + 1]);
            }
        }

        return cnt;
    }
};
