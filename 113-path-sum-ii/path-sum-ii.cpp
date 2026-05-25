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
    void func(TreeNode* root, int k,int sum,vector<vector<int>>&ans,vector<int>&curr){
        if(!root){
            return;
        }
        curr.push_back(root->val);sum+=root->val;
        if(!root->left and !root->right){
            if(k==sum)
            ans.push_back(curr);
            
        }
        func(root->left,k,sum,ans,curr);
        func(root->right,k,sum,ans,curr);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>>ans;vector<int>curr;
        func(root,targetSum,0,ans,curr);
        return ans;
    }
};