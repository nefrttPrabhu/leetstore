class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (!root) return ans;

        queue<TreeNode*> q;
        q.push(root);
        int c = 0;

        while (!q.empty()) {
            int n = q.size();
            vector<int> res; 
            stack<int> st;  
            
            for (int i = 0; i < n; ++i) {
                TreeNode* temp = q.front();
                q.pop();

                if (c % 2 == 0) {
                    res.push_back(temp->val);
                } else {
                    st.push(temp->val);
                }

                if (temp->left) q.push(temp->left);
                if (temp->right) q.push(temp->right);
            }

            if (c % 2 == 1) {
                while (!st.empty()) {
                    res.push_back(st.top());
                    st.pop();
                }
            }

            ans.push_back(res);
            c = !c; 
        }

        return ans;
    }
};
