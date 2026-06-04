class Solution {
public:
    int func(int n,vector<int>&dp){
        if(n==1 or n==0)return 1;
        if(dp[n]!=-1)return dp[n];
        return dp[n]=func(n-1,dp)+func(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        
        int prev1=1;int prev2=1;int curr=1;
        for(int i=2;i<=n;i++){
        
        
        curr=prev1+prev2;
        prev2=prev1;
        prev1=curr;
         }

        return curr;
    }
};