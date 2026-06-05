class Solution {
public:
    int func(vector<int>&arr,int i,vector<int>&dp){
        if(i<0)return 0;
        if(dp[i]!=-1)return dp[i];
        int pick=arr[i]+func(arr,i-2,dp);
        int notpick=func(arr,i-1,dp);
        return dp[i]= max(pick,notpick);
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        return func(nums,nums.size()-1,dp);
    }
};