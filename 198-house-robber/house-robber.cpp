class Solution {
public:
    int func(vector<int>&arr,int n,vector<int>& dp){
        if(n<0)return 0;
        if(dp[n]!=-1) return dp[n];
        int pick=func(arr,n-2,dp)+arr[n];
        int notpick=func(arr,n-1,dp);
        return dp[n]=max(pick,notpick);

    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size(),-1);
        // return func(nums,nums.size()-1,dp);
        if(nums.size()==1)return nums[0];
        dp[0]=nums[0];
        dp[1]=max(nums[0],nums[1]);
        for(int i=2;i<nums.size();i++){
            int pick=nums[i]+dp[i-2];
            int notpick=dp[i-1];
            dp[i]=max(pick,notpick);
        }
        return dp[nums.size()-1];
        
    }
};