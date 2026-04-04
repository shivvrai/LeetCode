class Solution {
public:int n=0;
    int func(vector<vector<int>>& arr,int i,int j,vector<vector<int>>& dp){
        if(i==n-1)return dp[i][j]=arr[i][j];
        if(dp[i][j]!=INT_MAX)return dp[i][j];
        int down=func(arr,i+1,j,dp);
        int digonal=func(arr,i+1,j+1,dp);
        return dp[i][j]=arr[i][j]+min(down,digonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        return func(triangle,0,0,dp);
    }
};