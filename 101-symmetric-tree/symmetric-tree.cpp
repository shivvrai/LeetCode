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
bool func(TreeNode* l,TreeNode* r){
    if(!l and !r)return true;
    if(!l or !r)return false;
    return l->val==r->val and func(l->left,r->right) and func(l->right,r->left);
}
    bool isSymmetric(TreeNode* root) {
        return func(root->left,root->right);
    }
};