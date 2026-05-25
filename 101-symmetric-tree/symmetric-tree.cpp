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
    bool func(TreeNode* p,TreeNode* q){
        if(!p and !q )return true;
        if(!p || !q )return false;
        return (p->val==q->val)and func(p->left,q->right) and func(q->left,p->right);
    }
    bool isSymmetric(TreeNode* root) {
        if(!root)return false;
       return func(root->left,root->right);
    }
};