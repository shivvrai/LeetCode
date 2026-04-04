class Solution {
public:
    int func(vector<int>& arr, int i, int sum) {
        if (i < 0) {
            return sum == 0 ? 1 : 0;
        }

        int add = func(arr, i - 1, sum - arr[i]);
        int sub = func(arr, i - 1, sum + arr[i]);

        return add + sub;
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return func(nums, nums.size() - 1, target);
    }
};