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
 int dfs(TreeNode* root,int &count)
{
  if(!root)  return 1;
  int right =dfs(root->right,count);
  int left = dfs(root->left,count); 
  if(right==2 || left==2) 
  {
    count++;
    return 0;
  }
  return min(left,right)+1; 
}
    int minCameraCover(TreeNode* root) {
        int count = 0;
        int k = dfs(root,count);
        if(k==2) count++;
        return count;        
    }
};