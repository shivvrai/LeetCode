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
unordered_map<int,int>mp;
int preindex=0;
TreeNode* build(vector<int>& preorder,int l,int h){
    if(l>h)return nullptr;
    int val=preorder[preindex++];
    TreeNode* node=new TreeNode(val);
    int mid=mp[val];
    node->left=build(preorder,l,mid-1);
    node->right=build(preorder,mid+1,h);
    return node;
}
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        for(int i=0;i<preorder.size();i++)mp[inorder[i]]=i;
        return build(preorder,0,preorder.size()-1);
    }
};