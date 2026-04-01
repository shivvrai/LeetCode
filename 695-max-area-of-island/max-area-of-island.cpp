class Solution {
public:
int maxi=0;
void dfs(vector<vector<int>>& grid,int i,int j,int& ans){
    int n=grid.size();
    int m=grid[0].size();
    if(i<0 or j<0 or j>=m or i>=n or grid[i][j]==0){
        return;
    }
    ans++;
    maxi=max(ans,maxi);
    grid[i][j]=0;
    dfs(grid,i-1,j,ans);
    dfs(grid,i,j-1,ans);
    dfs(grid,i,j+1,ans);
    dfs(grid,i+1,j,ans);
}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();int cnt=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    int ans=0;
                    dfs(grid,i,j,ans);
                    cnt++;
                }
            }
        }
        return maxi;
    }
};