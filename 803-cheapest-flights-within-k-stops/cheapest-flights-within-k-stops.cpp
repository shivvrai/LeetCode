class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1],i[2]});
        }
        vector<int>dist(n,INT_MAX);dist[src]=0;
        queue<pair<int,pair<int,int>>>q;

        q.push({0,{0,src}});
        while(!q.empty()){
            auto node=q.front();
            q.pop();
            int stop=node.first;
            int u=node.second.second;
            int wt=node.second.first;
            if(stop>k)continue;
            for(auto nextnode:adj[u]){
                int v=nextnode.first;
                int w=nextnode.second;
                if(wt+w<dist[v]){
                    dist[v]=wt+w;
                    q.push({stop+1,{dist[v],v}});
                }
            }

        }
        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];
    }
};