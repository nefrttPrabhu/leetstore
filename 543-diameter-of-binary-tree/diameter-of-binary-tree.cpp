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
    int depth(TreeNode* root, int &maxdiameter){
        if(!root) return 0;


        int ml = depth(root -> left, maxdiameter);
        int mr = depth(root -> right, maxdiameter);

        
        maxdiameter = max(maxdiameter, ml + mr);
        return max(ml, mr) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int maxdiameter = 0;
        depth(root, maxdiameter);

        return maxdiameter;
    }
};