class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i,int j,vector<vector<int>>& vis){
        if(i<0 ||j<0 ||i>=grid.size() || j>=grid[0].size() ||grid[i][j]=='0' ||  vis[i][j]==1){
            return;
        }
        vis[i][j]=1;
        dfs(grid,i-1,j,vis);
        dfs(grid,i+1,j,vis);
        dfs(grid,i,j-1,vis);
        dfs(grid,i,j+1,vis);
    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> vis(grid.size(), vector<int>(grid[0].size(), 0));
        int count=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(vis[i][j]==0 && grid[i][j]=='1'){
                    count++;
                    dfs(grid,i,j,vis);
                }
            }
        }
        return count;
    }
};