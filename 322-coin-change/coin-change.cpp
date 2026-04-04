class Solution {
public:
    int func(int amount,int i,vector<int>&arr,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(i<0)return 1e9;
        if(dp[i][amount]!=-1)return dp[i][amount];
        int pick=1e9;
        
        if(amount>=arr[i]){
            pick=1+func(amount-arr[i],i,arr,dp);
        
        }
        int notpick=func(amount,i-1,arr,dp);
       
        return dp[i][amount]=min(pick,notpick);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        int ans = func(amount, n-1, coins,dp);
        
        return (ans >= 1e9) ? -1 : ans;

    }
};