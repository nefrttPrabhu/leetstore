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

                int a = node ? node->val : -1; // use dummy value for null nodes

                if (node == nullptr) {
                    nullSeen = true;
                } else {
                    if (nullSeen) {
                        // Found a non-null node after a null — not complete
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
