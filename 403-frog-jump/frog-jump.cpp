class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones[1] != 1) return false;

        unordered_map<int, unordered_set<int>> dp;
        unordered_set<int> stoneSet(stones.begin(), stones.end());

        dp[1].insert(1);

        for (int stone : stones) {
            for (int jump : dp[stone]) {
                for (int step = jump - 1; step <= jump + 1; ++step) {
                    if (step > 0 && stoneSet.count(stone + step)) {
                        dp[stone + step].insert(step);
                    }
                }
            }
        }

        return !dp[stones.back()].empty();
    }
};
