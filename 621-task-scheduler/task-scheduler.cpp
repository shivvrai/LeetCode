class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>mp;
        for(auto i:tasks){
            mp[i]++;
        }
        priority_queue<int> pq;
        queue<pair<int,int>>q;
        for(auto i:mp)pq.push(i.second);
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int cnt=pq.top();pq.pop();
                cnt--;
                if(cnt>0)q.push({cnt,time+n});
            }
        if(!q.empty() and q.front().second==time){
            auto node=q.front();
            q.pop();
            pq.push(node.first);
        }
        }
return time;
    }
};