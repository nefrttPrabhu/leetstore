class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() <= 1) return true;

        stack<int> st;
        st.push(nums[0]);

        int flg = 0; 

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == st.top()) {
                st.push(nums[i]);
                continue;
            }

            if (flg == 0) {
                flg = (nums[i] > st.top()) ? 1 : -1;
                st.push(nums[i]);
            } 
            else if (flg == 1) { 
                if (nums[i] < st.top()) return false;
                st.push(nums[i]);
            } 
            else { 
                if (nums[i] > st.top()) return false;
                st.push(nums[i]);
            }
        }

        return true;
    }
};
