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
vector<vector<int>>ans;vector<int>curr;
    void func(TreeNode* root,int sum){
        if(!root)return;
        sum-=root->val;
        curr.push_back(root->val);
        if(sum==0 and !root->left and !root->right){
            ans.push_back(curr);
        }
        func(root->left,sum);
        func(root->right,sum);
        curr.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    func(root,targetSum);
    return ans;
    }
};