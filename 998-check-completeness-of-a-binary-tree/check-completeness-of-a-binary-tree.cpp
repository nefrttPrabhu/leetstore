class Solution {
public:
    bool isCompleteTree(TreeNode* root) {
        if (!root) return true;

        queue<TreeNode*> q;
        q.push(root);
        bool nullSeen = false;

        while (!q.empty()) {
            int n = q.size();

            while (n--) {
                auto node = q.front();
                q.pop();

                int a = node ? node->val : -1; 

                if (node == nullptr) {
                    nullSeen = true;
                } else {
                    if (nullSeen) {
                        return false;
                    }

                    q.push(node->left);
                    q.push(node->right);
                }
            }
        }

        return true;
    }
};
