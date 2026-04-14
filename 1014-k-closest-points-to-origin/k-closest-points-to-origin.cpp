class Solution {
public:
    class compare{
        public:
        bool operator()(vector<int>&a ,vector<int>&b){
            return (a[0]*a[0] +a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
        }
    };
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<vector<int>,vector<vector<int>>,compare>pq;
        for(auto i:points){
            
            pq.push(i);
            if(pq.size()>k)pq.pop();
        }
        vector<vector<int>>ans;
        while(pq.size()){
            ans.push_back(pq.top());pq.pop();
        }
        return ans;

    }
};