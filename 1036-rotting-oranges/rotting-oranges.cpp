class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>>q;
        int fresh=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==1)fresh++;
                if(grid[i][j]==2)q.push({i,j});

            }
        }int time=0;
        while(q.size()){
            int n=q.size();
            
            bool flag=false;
            vector<int>dx={-1,1,0,0};
            vector<int>dy={0,0,1,-1};
            for(int i=0;i<n;i++){
                auto p=q.front();
            q.pop();
            int r=p.first;
            int c=p.second;
                for(int i=0;i<4;i++){
                    int nr=r+dx[i];int nc=c+dy[i];
                    if(nc>=0 and nr>=0 and nc<grid[0].size() and nr<grid.size() and grid[nr][nc]==1){
                        q.push({nr,nc});
                        fresh--;
                        flag = true;
                        grid[nr][nc]=2;
                    }
                }
            }
            if(flag)time++;
            

        }
        return (fresh==0?time:-1);
    }
};