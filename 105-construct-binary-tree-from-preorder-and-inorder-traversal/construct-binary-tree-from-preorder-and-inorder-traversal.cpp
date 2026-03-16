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
        map<int,int> mp;int n=inorder.size()-1;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        if(inorder.size()==0)return nullptr;
        return build(preorder,0,n,inorder,0,n,mp);
    }
    private:
    TreeNode* build(vector<int>& preorder,int ps,int pe, vector<int>& inorder,int is,int ie,map<int,int>&mp){
        if(ps>pe || is>ie)return nullptr;
        int root=preorder[ps];
        TreeNode* node = new TreeNode(root);
        int iss=mp[root];

        int l=iss-is;
        node->left=build(preorder,ps+1,pe+l,inorder,is,iss-1,mp);
        node->right=build(preorder,ps+1+l,pe,inorder,iss+1,ie,mp);
    return node;
    }
};