class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int s = fruits.size();
        map<int, int> mp;
        int i = 0;
        int j = 0;
        int maxi = 0;

        while (j < s) {
            mp[fruits[j]]++;

            if (mp.size() <= 2) {
                j++;
            } else {
                int sum = 0;
                for (auto it : mp) {
                    sum += it.second;
                }
                maxi = max(maxi, sum - 1);
                mp[fruits[i]]--;
                if (mp[fruits[i]] == 0) {
                    mp.erase(fruits[i]);
                }
                i++;
                j++;
            }
        }

        int sum = 0;
        for (auto it : mp) sum += it.second;
        maxi = max(maxi, sum);

        return maxi;
    }
};
