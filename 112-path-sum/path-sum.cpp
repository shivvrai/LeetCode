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
    bool func(TreeNode* root, int targetSum,int sum){
        if(!root)return 0;
        sum+=root->val;
        if(!root->left and !root->right)return targetSum==sum;
        return func(root->left,targetSum,sum) or  func(root->right,targetSum,sum);
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root)return false;
        return func(root,targetSum,0);
    }
};