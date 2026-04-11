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
int index=0;
TreeNode* func(vector<int>&preorder,int min,int max){
    int i=index;
    if( i>=preorder.size() or  preorder[i]<min or preorder[i]>max)return nullptr;
    TreeNode* node=new TreeNode(preorder[index]);index++;
    node->left=func(preorder,min,preorder[i]);
    node->right=func(preorder,preorder[i],max);
    return node;

}
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        return func(preorder,INT_MIN,INT_MAX);
    }
};