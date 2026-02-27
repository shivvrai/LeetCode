class Solution {
public:
    int func(vector<int>&arr,vector<vector<vector<int>>>&dp,int i,int buy,int n,int cap){
        if(cap==2||i==n)return 0;
        if(dp[i][buy][cap]!=-1)return dp[i][buy][cap];
        int profit;
        if(buy==0){
            profit=max(0+func(arr,dp,i+1,buy,n,cap),-arr[i]+func(arr,dp,i+1,buy+1,n,cap));
        }
        if(buy==1){
            profit=max(0+func(arr,dp,i+1,buy,n,cap),arr[i]+func(arr,dp,i+1,buy-1,n,cap+1));
        }
        return dp[i][buy][cap]=profit;
    }
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(2,vector<int>(3,-1)));
        return func(arr,dp,0,0,n,0);
    }
};