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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>mp;int n=preorder.size();
        for(int i=0;i<n;i++){
            mp[inorder[i]]=i;
        }
        return build(preorder,inorder,0,n-1,0,n-1,mp);
    }
    private:
    TreeNode* build(vector<int>&preorder,vector<int>&inorder,int pres,int pree,int ins,int ine,map<int,int>&mp){
        if (pres > pree || ins > ine) return nullptr;
        TreeNode* root = new TreeNode(preorder[pres]);
        int inindex=mp[preorder[pres]];
        int lefts=inindex-ins;
        root->left=build(preorder,inorder,pres+1,pres+lefts,ins,inindex-1,mp);
        root->right=build(preorder,inorder,pres+lefts+1,pree,inindex+1,ine,mp);
        return root;

    }
};