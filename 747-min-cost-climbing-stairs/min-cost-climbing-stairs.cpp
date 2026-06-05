class Solution {
public:
    int func(vector<int>&cost,vector<int>&dp,int n){
        if(n<=1)return cost[n];
        if(dp[n]!=-1)return dp[n];
        int one=func(cost,dp,n-1);
        int two=func(cost,dp,n-2);
        return dp[n]=cost[n]+min(one,two);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        vector<int>dp(cost.size(),-1);
    return min(func(cost,dp,n-1),func(cost,dp,n-2));
    }
};