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
    void func(TreeNode *root,int i
  ,vector<int>&ans){
      if(!root)return;
      if(ans.size()==i)ans.push_back(root->val);
      else ans[i]=root->val;
      if(root->left)func(root->left,i+1,ans);
      if(root->right)func(root->right,i+1,ans);
      
      
  }
    vector<int> rightSideView(TreeNode *root) {
        // code here
        vector<int> ans;
        func(root,0,ans);
        return ans;
        
        
    }
};