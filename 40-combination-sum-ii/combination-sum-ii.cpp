class Solution {
public:
    void func(int i,vector<int>&curr,vector<int>&arr,vector<vector<int>>&ans,int sum){
        if(sum==0){
            ans.push_back(curr);
            return;
        }
        if(i>=arr.size() or sum<0)return;
        for(int j=i;j<arr.size();j++){
            if(j>i and arr[j]==arr[j-1])continue;
            curr.push_back(arr[j]);
            func(j+1,curr,arr,ans,sum-arr[j]);
            curr.pop_back();
        }
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
         vector<int>curr;
        
        vector<vector<int>>ans;
        func(0,curr,candidates,ans,target);
        return ans;
    }
};