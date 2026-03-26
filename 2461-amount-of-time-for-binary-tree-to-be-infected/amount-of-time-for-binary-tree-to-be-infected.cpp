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
int ans=0;
void func(queue<pair<TreeNode*, int>>q,map<TreeNode*,TreeNode*>parent,unordered_set<TreeNode*>&visited){
    while(q.size()){
        TreeNode* root=q.front().first;int t=q.front().second;
        q.pop();
ans=max(ans,t);

    if(root->left and !visited.count(root->left)){
        q.push({root->left,t+1});visited.insert(root->left);
    }
    if(root->right and !visited.count(root->right)){
        q.push({root->right,t+1});visited.insert(root->right);
    }
    if(parent[root] and !visited.count(parent[root])){
        q.push({parent[root],t+1});visited.insert(parent[root]);
    }}
}
    void parents(TreeNode*root, map<TreeNode*,TreeNode*>&mp,TreeNode* parent){
        if(!root)return;
        mp[root]=parent;
        parents(root->left,mp,root);
        parents(root->right,mp,root);
    }
    TreeNode* seach(TreeNode* root, int s){
        if(!root)return nullptr;

        if(s==root->val)return root;
        TreeNode* left=seach(root->left,s);
        TreeNode* right=seach(root->right,s);
        if(!left)return right;
        return left;
        
    }
    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*,TreeNode*> parent;
        parents(root,parent,nullptr);
        int n=parent.size();
        unordered_set<TreeNode*> visited;
        queue<pair<TreeNode*,int>>q;
        TreeNode* node=seach(root,start);
        q.push({node,0});visited.insert(node);
        func(q,parent,visited);
        return ans;
        


    }
};