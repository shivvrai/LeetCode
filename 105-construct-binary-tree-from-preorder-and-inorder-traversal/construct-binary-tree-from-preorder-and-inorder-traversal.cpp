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
    TreeNode* build(vector<int>&preorder,int& preindex,map<int,int>&mp,int l,int h){
       if(l>h)return nullptr;
        int val=preorder[preindex++];
        TreeNode* node=new TreeNode(val);
        int mid=mp[val];
        node->left=build(preorder,preindex,mp,l,mid-1);
        node->right=build(preorder,preindex,mp,mid+1,h);
        return node;

            }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;
        for(int i=0;i<inorder.size();i++)mp[inorder[i]]=i;int preindex=0;
        return build(preorder,preindex,mp,0,inorder.size()-1);
    }
};