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
public:int ans=INT_MIN;
    int func(TreeNode* root){
        if(!root)return 0;
        int left=func(root->left);
        if(left<0)left=0;
        int right=func(root->right);
        if(right<0)right=0;
        ans=max(root->val+left+right,ans);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        func(root);return ans;
    }
};