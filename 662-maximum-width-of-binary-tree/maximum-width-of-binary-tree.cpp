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
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<long long ,TreeNode*>> q;if(!root)return 0;
        int ans=0;
        q.push({0,root});
        while(q.size()){
            int n=q.size();
            long long  level=q.front().first;
            
                long long first=0;long long last=0;
            for(int i=0;i<n;i++){
                TreeNode* node=q.front().second;
                long long  rem=q.front().first-level;
                q.pop();
                if(i==0)first=rem;
                if(i==n-1)last=rem;
                
                
                if(node->left)q.push({2*rem+1,node->left});
                if(node->right)q.push({2*rem+2,node->right});
            }
            ans=max(ans,(int)(last-first+1));
            
        }
        return ans;
    }
};