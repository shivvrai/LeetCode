class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());

        long long ans = (long long)nums[0] + nums[1] + nums[2];

        for (int i = 0; i < nums.size() - 2; i++) {
            int j = i + 1;
            int k = nums.size() - 1;

            while (j < k) {
                long long sum = (long long)nums[i] + nums[j] + nums[k];

                if (llabs(sum - target) < llabs(ans - target))
                    ans = sum;

                if (sum == target)
                    return target;

                if (sum < target)
                    j++;
                else
                    k--;
            }
        }

        return (int)ans;
    }
};