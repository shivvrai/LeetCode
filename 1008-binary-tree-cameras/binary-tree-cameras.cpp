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
//0 camera is needed
//1 camera is not needed 
//2 camera is there 
int cam=0;
    int func(TreeNode* root){
        if(!root)return 1;

        int left=func(root->left);
        int right=func(root->right);
        if(left ==0 or right ==0){cam++;return 2;}
        if(left ==2 or right ==2)return 1;
        return 0;


    }
    int minCameraCover(TreeNode* root) {
        if(func(root)==0)cam++;
        return cam;
    }
};