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
    int lheight(TreeNode* root){
        if(!root)return 0;
        return 1+lheight(root->left);

    }
    int rheight(TreeNode* root){
        if(!root)return 0;
        return 1+rheight(root->right);

    }
    int countNodes(TreeNode* root) {
        if(!root)return 0;
        int l=lheight(root);
        int r=rheight(root);
        if(l==r)return (1<<l )-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};