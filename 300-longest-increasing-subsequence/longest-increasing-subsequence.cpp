class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> st;
        for (int i = 0; i < nums.size(); i++) {
            if (st.empty() || nums[i] > st.back()) {
                st.push_back(nums[i]);
            } 
            else {
                for (int j = 0; j < st.size(); j++) {
                    if (st[j] >= nums[i]) {
                        st[j] = nums[i];
                        break;
                    }
                }
            }
        }
        return st.size();
    }
};
