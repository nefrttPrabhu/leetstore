// class Solution {
// public:
//     unordered_map<int, int> postIndex;
//     int preIdx = 0;

//     TreeNode* construct(vector<int>& preorder, vector<int>& postorder, int left, int right) {
//         if (preIdx >= preorder.size() || left > right) return nullptr;

//         TreeNode* root = new TreeNode(preorder[preIdx++]);

//         if (left == right) return root;

//         int leftSubtreeIdx = postIndex[preorder[preIdx]];

//         root->left = construct(preorder, postorder, left, leftSubtreeIdx);
//         root->right = construct(preorder, postorder, leftSubtreeIdx + 1, right - 1);

//         return root;
//     }

//     TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
//         int n = postorder.size();
//         for (int i = 0; i < n; ++i) postIndex[postorder[i]] = i;
//         return construct(preorder, postorder, 0, n - 1);
//     }
// };



class Solution {
public:
    int index=0;
    TreeNode* build(vector<int>& pre,vector<int>& post,int s,int e){
        if(s>e or index>pre.size()-1) return NULL;
        TreeNode* root=new TreeNode(pre[index]);
        index++;
        if(s==e) return root;
        int ni=0;
        for(int i=s;i<=e-1;i++){
            if(post[i]==pre[index]){
                ni=i;
                break;
            }
        }
        root->left=build(pre,post,s,ni);
        root->right=build(pre,post,ni+1,e-1);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        return build(preorder,postorder,0,preorder.size()-1);
    }
};