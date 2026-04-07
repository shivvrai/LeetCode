class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> visited(n, -1);

        for(int i = 0; i < n; i++) {
            if(visited[i] == -1) {
                queue<int> q;
                q.push(i);
                visited[i] = 0;

                while(!q.empty()) {
                    int u = q.front();
                    q.pop();

                    for(auto v : graph[u]) {
                        if(visited[v] == -1) {
                            visited[v] = 1 - visited[u];
                            q.push(v);
                        }
                        else if(visited[v] == visited[u]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};