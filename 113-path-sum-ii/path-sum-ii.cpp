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
void func(TreeNode* root,int sum,vector<int>&path,vector<vector<int>>&ans){
    if(!root)return;
    if(!root->left and !root->right and sum-root->val==0){
        path.push_back(root->val);
        ans.push_back(path);
        path.pop_back();
        return;
    }
    path.push_back(root->val);
    func(root->left,sum-root->val,path,ans);
    func(root->right,sum-root->val,path,ans);
    path.pop_back();
}
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>path;
        vector<vector<int>>ans;
        func( root, targetSum,path,ans);
        return ans;
    }
};