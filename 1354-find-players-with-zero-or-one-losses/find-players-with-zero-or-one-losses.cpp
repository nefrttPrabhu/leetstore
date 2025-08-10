class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> olost;
        vector<int> nlost;
        set<int> st;
        map<int, int> mp;

        for(auto it : matches){
            mp[it[1]]++;
        }

        for(auto it : mp){
            if(it.second == 1){
                olost.push_back(it.first);
            }
        }

        for(auto it : matches){
            if(mp.find(it[0]) == mp.end() && st.find(it[0]) == st.end()){
                nlost.push_back(it[0]);
                st.insert(it[0]);
            }
        }

        sort(nlost.begin(), nlost.end());
        sort(olost.begin(), olost.end());

        return {nlost, olost};
    }
};