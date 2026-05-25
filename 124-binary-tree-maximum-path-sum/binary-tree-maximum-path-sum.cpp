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
    int func(TreeNode* root,int &ans){
        if(!root)return 0;
        int lh=func(root->left,ans);
        if(lh<0)lh=0;
        int rh=func(root->right,ans);
        if(rh<0)rh=0;
        ans=max(ans,root->val+lh+rh);
        return root->val+max(lh,rh);
    }
    int maxPathSum(TreeNode* root) {int ans=INT_MIN;
        func(root,ans);
        return ans;
    }
};