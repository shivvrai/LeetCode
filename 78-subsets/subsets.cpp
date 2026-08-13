class Solution {
public:
     void func(int j,vector<int>&curr,vector<int>&arr,vector<vector<int>>&ans){
        ans.push_back(curr);
        for(int i=j;i<arr.size();i++){
            curr.push_back(arr[i]);
            func(i+1,curr,arr,ans);
            curr.pop_back();
        }
     }
    vector<vector<int>> subsets(vector<int>& arr) {
        vector<vector<int>>ans;
        vector<int>curr;
        func(0,curr,arr,ans);
        return ans;
        
    }
};