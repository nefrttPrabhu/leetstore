class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int, int> mp;
        for(auto it : arr) mp[it]++;

        int maxi = -1;
        for(auto it : mp){
            if(it.second == it.first) maxi = max(maxi, it.first);
        }

        return maxi;
    }
};