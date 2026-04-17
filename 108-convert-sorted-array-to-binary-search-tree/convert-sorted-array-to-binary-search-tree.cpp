class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return build(nums, 0, nums.size()-1);
    }

    TreeNode* build(vector<int>& nums, int start, int end) {
        if (start > end) return nullptr;
        int mid = (start + end) / 2;
        TreeNode* root = new TreeNode(nums[mid]);
        root->left = build(nums, start, mid-1);
        root->right = build(nums, mid + 1, end);
        return root;
    }
};