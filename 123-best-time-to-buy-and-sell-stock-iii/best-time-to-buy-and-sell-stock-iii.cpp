class Solution {
public:int n=0;
    int func(vector<int>& arr,int i,int buy,int cap,vector<vector<vector<int>>>& dp){
        if(cap==0 or i==n)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit=0;
        if(buy){
            profit=max(-arr[i]+func(arr,i+1,0,cap,dp),func(arr,i+1,1,cap,dp));
        }
        else{
            profit=max(arr[i]+func(arr,i+1,1,cap-1,dp),func(arr,i+1,0,cap,dp));
        }
        return dp[i][buy][cap]=profit;
    }

    int maxProfit(vector<int>& prices) {
        n=prices.size();int cap=2;
        vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(cap+1,-1)));
        return func(prices,0,1,cap,dp);
    }
};