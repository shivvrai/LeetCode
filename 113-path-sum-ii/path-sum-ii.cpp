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
    void func(TreeNode* root,vector<int>&curr,vector<vector<int>>& ans,int sum,int &target){
        sum+=root->val;       
        curr.push_back(root->val);
        if(!root->left and !root->right and sum==target)ans.push_back(curr);
        if(root->left)func(root->left,curr,ans,sum,target);
        if(root->right)func(root->right,curr,ans,sum,target);
        
        curr.pop_back();

        
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>curr;
        vector<vector<int>>ans;
        if(!root)return ans;
        func(root,curr,ans,0,targetSum);
        return ans;
    }
};