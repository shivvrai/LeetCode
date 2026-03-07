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
int maxi=INT_MIN;
int func(TreeNode* root){
    if(!root)return 0;
        int left=func(root->left);
        int right=func(root->right);
        maxi=max(maxi,1+left+right);
        return 1+max(left,right);
}
    int diameterOfBinaryTree(TreeNode* root) {
        int ans=func(root);
        return maxi-1;

    }
};