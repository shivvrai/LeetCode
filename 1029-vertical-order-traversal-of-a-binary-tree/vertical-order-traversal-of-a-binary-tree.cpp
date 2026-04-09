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
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int,map<int,multiset<int>>>mp;
        //int v int h int e
        queue<pair<TreeNode*,pair<int,int>>>q;
        q.push({root,{0,0}});
        while(!q.empty()){
            int n=q.size();
            for(int i=0;i<n;i++){
                auto node=q.front().first;
                int v=q.front().second.first;
                int h=q.front().second.second;
                q.pop();
                mp[v][h].insert(node->val);
                if(node->left)q.push({node->left,{v-1,h+1}});
                if(node->right)q.push({node->right,{v+1,h+1}});
            }
        }
        vector<vector<int>>ans;
        for(auto i:mp){
            vector<int>curr;
            for(auto j:i.second){
                for(auto val : j.second){ 
                    curr.push_back(val);
                }
            }
            ans.push_back(curr);
        }
        return ans;
    }
};