class Solution {
public:
    // int func(){
    //     if()
    // }

    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        
        queue<pair<int,pair<int,int>>> q;
        vector<vector<int>> visited(n, vector<int>(m, -1));

        // push all rotten oranges
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 2) {
                    q.push({0, {i, j}});
                    visited[i][j] = 1;
                }
            }
        }

        int maxi = 0;
        vector<int> dr = {0, 1, -1, 0};
        vector<int> dc = {-1, 0, 0, 1};

        while(!q.empty()) {
            auto t = q.front();
            q.pop();

            int time = t.first;
            int i = t.second.first;
            int j = t.second.second;

            maxi = max(maxi, time);

            for(int k = 0; k < 4; k++) {
                int ni = i + dr[k];
                int nj = j + dc[k];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m &&
                   grid[ni][nj] == 1 && visited[ni][nj] == -1) {

                    visited[ni][nj] = 1;
                    q.push({time + 1, {ni, nj}});
                }
            }
        }
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(grid[i][j] == 1 && visited[i][j] == -1) {
                    return -1;
                }
            }
        }

        return maxi;
    }
};