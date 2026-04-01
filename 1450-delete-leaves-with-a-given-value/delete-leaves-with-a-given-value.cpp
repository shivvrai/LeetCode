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
    TreeNode* func(TreeNode* root,int k){
        if(!root )return nullptr;
        root->left=func(root->left,k);
        root->right=func(root->right,k);
        if(!root->left and !root->right and root->val == k and 1)return nullptr;
        return root; 
        
    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return func(root,target);
       
    }
};