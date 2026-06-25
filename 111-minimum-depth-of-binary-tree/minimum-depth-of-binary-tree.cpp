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
    int func(TreeNode* root){
        if(!root)return 0;
        if(!root->left)return 1+func(root->right);
        if(!root->right)return 1+func(root->left);
        int lh=func(root->left);
        int rh=func(root->right);
        return 1+min(lh,rh);
    }
    int minDepth(TreeNode* root) {
        return func(root);
    }
};