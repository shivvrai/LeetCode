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
class BSTIterator {
public:
        stack<TreeNode*>st;
        TreeNode* curr=nullptr;
    BSTIterator(TreeNode* root) {
        this->curr=root;
        update(curr);

    }
    
    int next() {
        auto node=st.top();
        int data=node->val;
        st.pop();
        update(node->right);
        return data;
    }
    
    bool hasNext() {
        return st.size();
    }
    void update(TreeNode* node){
        while(node){ 
            st.push(node);
            node=node->left;
        }
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */