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
int sum=0;
void func(TreeNode* root,int isleft){
    if(!root)return;
    if(!root->left and !root->right and isleft)sum+=root->val;
    if(root->left)func(root->left,1);
    if(root->right)func(root->right,0);
    
}
    int sumOfLeftLeaves(TreeNode* root) {
        func(root,0);
        return sum;
    }
};