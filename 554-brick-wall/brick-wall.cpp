class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n=wall.size();
        unordered_map<int,int>mp;
        for(auto row:wall){
            long long int sum=0;
            for(int i=0;i<row.size()-1;i++){
                sum+=row[i];
                mp[sum]++;
            }
        }
        int maxi=0;
        for(auto i:mp){
            maxi=max(maxi,i.second);
        }
        return n-maxi;
    }
};