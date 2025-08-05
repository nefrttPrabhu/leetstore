class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        map<int, int> mp;

        for (int i = 0; i < matches.size(); i++) {
            mp[matches[i][1]]++;
        }

        vector<int> olost;
        for (auto it : mp) {
            if (it.second == 1) {
                olost.push_back(it.first);
            }
        }

        set<int> st;  
        vector<int> nlost;
        for (int i = 0; i < matches.size(); i++) {
            int winner = matches[i][0];
            if (mp.find(winner) == mp.end() && st.find(winner) == st.end()) { 
                nlost.push_back(winner);
                st.insert(winner);
            }
        }

        sort(nlost.begin(), nlost.end());
        sort(olost.begin(), olost.end());

        return {nlost, olost};
    }
};
