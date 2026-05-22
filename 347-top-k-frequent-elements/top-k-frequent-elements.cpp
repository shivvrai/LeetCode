class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int,int>mp;int maxfreq=0;vector<int>ans;
        for(auto i:nums){
            mp[i]++;
        }
         priority_queue<pair<int,int>> pq;

        for(auto it : mp) {
            pq.push({it.second, it.first});
        }
        int c=0;
        while(c!=k){
            ans.push_back(pq.top().second);pq.pop();
            c++;
        }
        return ans;
    }
};