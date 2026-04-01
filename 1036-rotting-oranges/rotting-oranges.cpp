class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();int freshoranges=0,time=0;
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2){
                    q.push({i,j});
                }
                else if(grid[i][j]==1)freshoranges++;
            }
        }
        vector<int> dx={1,-1,0,0};
        vector<int> dy={0,0,-1,1};
        if(freshoranges==0)return time;
        while(!q.empty()){
            int level=q.size();
            bool rotten=false;
            for(int i=0;i<level;i++){
                auto p=q.front();
                int x=p.first;
                int y=p.second;
                q.pop();
                for(int i=0;i<4;i++){
                    int nx=x+dx[i];
                    int ny=y+dy[i];
                    if(nx>=0 and ny>=0 and nx<n and ny<m and grid[nx][ny]==1){
                        q.push({nx,ny});
                        grid[nx][ny]=2;
                        freshoranges--;rotten=true;
                    }
                }
            }
            if(rotten)time++;
        }
        return (freshoranges==0 ? time : -1);
    }
};