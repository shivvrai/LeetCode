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
    TreeNode * prev=nullptr;
    bool func(TreeNode* root){
        if(!root)return true;
        bool left= func(root->left);
        if(prev and prev->val>=root->val)return false;
        prev=root;
        
        bool right= func(root->right);
        
        return left and right;

    }
    bool isValidBST(TreeNode* root) {
        return func(root);
    }
};