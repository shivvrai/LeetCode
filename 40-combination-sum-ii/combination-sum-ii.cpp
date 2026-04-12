class Solution {
public:int k=0;
    void func(int index,vector<vector<int>>&ans,
        vector<int>&curr,vector<int>&arr,int sum){
        if(sum==k){
            ans.push_back(curr);
            return;
        }
        for(int i=index;i<arr.size();i++){
            if(i>index and arr[i]==arr[i-1])continue;
            if(sum+arr[i]<=k){
                sum+=arr[i];
                curr.push_back(arr[i]);
                func(i+1,ans,curr,arr,sum);
                curr.pop_back();
                sum-=arr[i];
            }

        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>ans;k=target;
        sort(candidates.begin(),candidates.end());
        vector<int>curr;
        func(0,ans,curr,candidates,0);
        return ans;
    }
};