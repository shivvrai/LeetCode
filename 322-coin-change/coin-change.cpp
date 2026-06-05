class Solution {
public:
    int func(int amount,int n,vector<int>&arr,vector<vector<int>>&dp){
        if(amount==0){
            return 0;
        }

        if(n<0)return 1e9;
        if(dp[n][amount] != -1)
    return dp[n][amount];
        int pick=1e9;
        if(amount-arr[n]>=0){
            pick=1+func(amount-arr[n],n,arr,dp);
        }
        int notpick=func(amount,n-1,arr,dp);
        return dp[n][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
         int ans =
            func(amount, n - 1, coins, dp);

        return ans >= 1e9 ? -1 : ans;

    }
};