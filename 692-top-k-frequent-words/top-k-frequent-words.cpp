class Solution {
public:
    class compare{
        public:
        bool operator()(pair<string ,int>&a,pair<string,int>&b){
            if(a.second==b.second)return a.first < b.first;
            return a.second > b.second;//minheap
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<string,int>,vector<pair<string,int>>,compare>pq;
        map<string,int>mp;
        for(auto i:words){
            mp[i]++;
        }
        for(auto i:mp){
            pq.push({i.first,i.second});
            if(pq.size()>k)pq.pop();
        }
        vector<string>ans;
        while(pq.size()){
            ans.push_back(pq.top().first);
            pq.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};