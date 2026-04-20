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
public:vector<vector<int>>ans;
vector<int>curr;

    void func(TreeNode* root,int k){
        if(!root)return;
        curr.push_back(root->val);
        if(k-root->val==0 and !root->left and !root->right){
            ans.push_back(curr);
        }
        func(root->left,k-root->val);
        func(root->right,k-root->val);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        func(root,targetSum);
        return ans;

    }
};