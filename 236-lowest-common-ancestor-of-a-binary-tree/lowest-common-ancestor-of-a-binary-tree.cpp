/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL) 
            return NULL; 
            
        if (root == p || root == q) 
            return root; 

        TreeNode* l = lowestCommonAncestor(root->left, p, q); 
        TreeNode* r = lowestCommonAncestor(root->right, p, q); 

        if (l && r) 
            return root; 
            
        if(l) return l; 
        if(r) return r;
        return NULL;
    }
};




/*
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // Base case: null node
        if (!root) return nullptr;
        
        // If the current node is either p or q, return it
        if (root == p || root == q) return root;
        
        // Recur for left and right children
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        // If both left and right return a non-null value, current node is LCA
        if (left && right) return root;
        
        // Otherwise, return the non-null child (or null if both are null)
        return left ? left : right;
    }
};
*/


/*
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        if(root == NULL)
            return NULL;

        if(root->val == p->val || root->val == q->val)
            return root;

        TreeNode* leftChild = lowestCommonAncestor(root->left, p, q);
        TreeNode* rightChild = lowestCommonAncestor(root->right, p, q);

        if(leftChild == NULL && rightChild == NULL)
            return NULL;

        else if(leftChild != NULL && rightChild == NULL)
            return leftChild;

        else if(leftChild == NULL && rightChild != NULL)
            return rightChild;

        else
            return root;
    }
*/