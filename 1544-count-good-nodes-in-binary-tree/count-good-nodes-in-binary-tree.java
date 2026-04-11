class Solution {

    public int dfs(TreeNode root, int maxSoFar) {
        if (root == null) return 0;

        int count = 0;

        // Check if current node is good
        if (root.val >= maxSoFar) {
            count = 1;
            maxSoFar = root.val;
        }

        // Traverse left and right
        count += dfs(root.left, maxSoFar);
        count += dfs(root.right, maxSoFar);

        return count;
    }

    public int goodNodes(TreeNode root) {
        return dfs(root, root.val);
    }
}