class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n=grid.size();if(grid[0][0]!=0)return -1;if(n==1)return 1;
        queue<pair<int,int>>q;
        q.push({0,0});
        vector<int> dx={1,1,-1,-1,-1,1,0,0};int count=0;
        vector<int> dy={-1,0,1,0,-1,1,1,-1};grid[0][0]=1;
        while(!q.empty()){
            int l=q.size();

            for(int i=0;i<l;i++){
                auto p=q.front();
                int x=p.first;
                int y=p.second;
                q.pop();
                
                for(int j=0;j<8;j++){
                    int nx=x+dx[j];
                    int ny=y+dy[j];
                    if(nx>=0 and ny>=0 and nx<n and ny<n and grid[nx][ny]==0){
                        if(nx==n-1 and ny==n-1)return count+2;
                        q.push({nx,ny});
                        grid[nx][ny]=1;

                    }
                }
            }count++;
        }

        return -1;
    }
};