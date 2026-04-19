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
    unordered_map<TreeNode*,int>dp;
    int func(TreeNode* root){
        if(!root)return 0;
        if(dp.count(root))return dp[root];
        int notake=func(root->left)+func(root->right);
        int take=root->val;
        if(root->left){
            take+=func(root->left->left)+func(root->left->right);
        }
        if(root->right){
            take+=func(root->right->left)+func(root->right->right);
        }
        return dp[root]=max(take,notake);
    }
    int rob(TreeNode* root) {
        return func(root);
    
    }
};