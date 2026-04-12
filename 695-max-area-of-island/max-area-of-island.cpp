class Solution {
public:
    int dfs(vector<vector<int>>& grid,int i,int j){
        if(i<0 or j<0 or i>=grid.size() or j>=grid[0].size() or grid[i][j]==0)return 0;
         int cnt=1;
         grid[i][j]=0;
        cnt+=dfs(grid,i+1,j);
        cnt+=dfs(grid,i,j+1);
        cnt+=dfs(grid,i,j-1);
        cnt+=dfs(grid,i-1,j);
        return cnt;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size();int maxarea=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    maxarea=max(maxarea,dfs(grid,i,j));
                }
            }
        }
        return maxarea;
    }
};