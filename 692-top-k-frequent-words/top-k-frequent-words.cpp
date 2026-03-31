class Solution {
public:
    struct compare{
        bool operator()(pair<string,int>& p1 ,pair<string,int>& p2){
            if(p1.second==p2.second)return p1.first>p2.first;
            return p1.second<p2.second;
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string,int>mp;
        for(auto i:words)mp[i]++;
        priority_queue<pair<string,int>, vector<pair<string,int>>, compare> pq;
         for (auto &p : mp) {
            pq.push(p);
        }
        vector<string>ans;
        for(int i=0;i<k;i++){
                auto node=pq.top();
                pq.pop();

                ans.push_back(node.first);
        }
        return ans;
    }
};