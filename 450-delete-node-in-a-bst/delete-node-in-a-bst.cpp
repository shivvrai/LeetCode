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
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root)return root;
        if(root->val>key){
            root->left=deleteNode(root->left,key);
        }
        else if(root->val<key){
            root->right=deleteNode(root->right,key);
        }
        else{
            if(!root->right and !root->left)return nullptr;
            if(!root->right or !root->left){
                return root->right? root->right: root->left;
            }
            TreeNode* ip=root->left;
            while(ip->right){
                ip=ip->right;
                
            }
            root->val=ip->val;
            root->left=deleteNode(root->left,ip->val);
        }
        return root;
    }
};