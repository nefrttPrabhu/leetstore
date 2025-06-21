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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> q;
        vector<vector<int>> ans;
        int flag = 0;
    
        q.push(root);

        while(!q.empty()) {
            int size = q.size();
            vector<int> temp;
            
            while(size--) {
                temp.push_back(q.front()->val);
                if(q.front()->left) {
                    q.push(q.front()->left);
                }
                if(q.front()->right) {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            if(flag % 2 == 1) {
                reverse(temp.begin(), temp.end());
            } 
            ans.push_back(temp);
            flag++;
        }
        return ans;
    }
};