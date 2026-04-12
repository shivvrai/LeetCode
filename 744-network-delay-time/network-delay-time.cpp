class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1);
        for(auto i:times){
            adj[i[0]].push_back({i[1],i[2]});

        }
        int t=0;
        vector<int>time(n+1,INT_MAX);time[k]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        pq.push({0,k});
        while(!pq.empty()){
            auto node=pq.top();
            pq.pop();
            int u=node.second;
            int w=node.first;
            if (w > time[u]) continue;
            t=max(t,w);
            for(auto v:adj[u]){
                if(w+v.second<time[v.first]){
                    time[v.first]=w+v.second;
                    pq.push({w+v.second,v.first});
                }
            }
        }
        for(int i=1;i<=n;i++){
            if(time[i]==INT_MAX)return -1;

        }
        return t;

    }
};