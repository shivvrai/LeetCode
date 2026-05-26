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
    bool func(TreeNode* root,vector<long long>cond){
        if(!root)return true;
        if(root->val<=cond[0] || root->val>=cond[1])return false;
        bool left=func(root->left,{cond[0],root->val});
        bool right=func(root->right,{root->val,cond[1]});
        return left and right;
    }
    bool isValidBST(TreeNode* root) {
        vector<long long >cond={LLONG_MIN,LLONG_MAX};
        return func(root,cond);
        

    }
};