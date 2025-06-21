/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(!p || !q) {
            return p == q;
        }

        if(!isSameTree(p->left, q->left)) return false;
        if(!isSameTree(p->right, q->right)) return false;
        // if(!a || !b) return false;
        return p->val == q->val;
    }
};