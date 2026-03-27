class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& ans, vector<int>& arrs) {
        ans.push_back(arrs);
        vector<vector<int>>arr;
        sort(ans.begin(),ans.end());
        for(auto i:ans){
            if(!arr.size())arr.push_back(i);
            else{
                if(arr.back()[1]>=i[0] ){arr.back()[1] = max(arr.back()[1], i[1]);}
                else arr.push_back(i);
            }
        }
        return arr;
    }
};