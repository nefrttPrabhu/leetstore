class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {
        stack<pair<TreeNode*, int>> st; // Stack to store nodes with their depth
        int i = 0, n = traversal.size();

        while (i < n) {
            int depth = 0;

            // Count the number of dashes (depth)
            while (i < n && traversal[i] == '-') {
                depth++;
                i++;
            }

            // Extract node value
            int value = 0;
            while (i < n && isdigit(traversal[i])) {
                value = value * 10 + (traversal[i] - '0');
                i++;
            }

            // Create the new node
            TreeNode* node = new TreeNode(value);

            // If stack is empty, this is the root node
            if (st.empty()) {
                st.push({node, depth});
                continue;
            }

            // Find the parent node by popping until correct depth is found
            while (!st.empty() && st.top().second >= depth) {
                st.pop();
            }

            // Attach the new node to its parent
            if (st.top().first->left == nullptr) {
                st.top().first->left = node;
            } else {
                st.top().first->right = node;
            }

            // Push the new node onto the stack
            st.push({node, depth});
        }

        // The root node is at the bottom of the stack
        while (st.size() > 1) {
            st.pop();
        }

        return st.top().first;
    }
};
