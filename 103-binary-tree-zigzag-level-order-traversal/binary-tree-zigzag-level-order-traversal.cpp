
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        vector<vector<int>> ans;

        if (!root) return ans;

        q.push(root);
        int c = 0;

        while (!q.empty()) {
            TreeNode* node = NULL;
            int n = q.size();
            vector<int> res;

            while (n--) {
                node = q.front();
                q.pop();
                res.push_back(node -> val);

                if (node -> left) q.push(node -> left);
                if (node -> right) q.push(node -> right);
            }

            if (c) reverse(res.begin(), res.end());
            ans.push_back(res);
            c = !c; 
        }

        return ans;
    }
};
