class Solution {
public:
    bool fng(vector<int>& vis, vector<int>& ans, int index, int n) {
        if (index == ans.size()) {
            return true;
        }

        if (ans[index] != -1) {
            return fng(vis, ans, index + 1, n);
        }

        for (int nums = n; nums > 0; nums--) {
            if (!vis[nums]) {
                vis[nums] = true;
                ans[index] = nums;

                if (nums == 1) {
                    if (fng(vis, ans, index + 1, n)) {
                        return true;
                    }
                } else {
                    // Check if we can place the second occurrence of the number
                    if (index + nums < ans.size() && ans[index + nums] == -1) {
                        ans[index + nums] = nums;
                        if (fng(vis, ans, index + 1, n)) {
                            return true;
                        }
                        ans[index + nums] = -1;
                    }
                }

                ans[index] = -1;
                vis[nums] = false;
            }
        }
        return false;
    }

    vector<int> constructDistancedSequence(int n) {
        vector<int> vis(n + 1, false); 
        vector<int> ans(2 * n - 1, -1); 
        fng(vis, ans, 0, n);
        return ans;
    }
};
