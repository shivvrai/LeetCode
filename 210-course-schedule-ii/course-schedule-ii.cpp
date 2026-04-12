class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& pre) {
        vector<int>indegree(n,0);vector<int>ans;
        vector<vector<int>>adj(n);
        for(auto i:pre){
            adj[i[1]].push_back(i[0]);
            indegree[i[0]]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++){
            if(!indegree[i])q.push(i);
        }
        while(!q.empty()){
            int u=q.front();
            ans.push_back(u);
            q.pop();
            for(int v:adj[u]){
                indegree[v]--;
                if(indegree[v]==0)q.push(v);
            }
        }
        vector<int>emp;
        if(ans.size()!=n)return emp;
        return ans;
    }
};