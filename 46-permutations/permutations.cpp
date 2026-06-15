class Solution {
public:
    void func(vector<int>&curr,vector<int>&arr,vector<vector<int>>&ans,vector<bool>&used){
        if(curr.size()==arr.size()){
            ans.push_back(curr);return;
        }
        for(int i=0;i<arr.size();i++){
            if(used[i])continue;
            curr.push_back(arr[i]);
            used[i]=true;
            func(curr,arr,ans,used);
            used[i]=false;
            curr.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        int n=nums.size();
        vector<int>curr;
        vector<bool>used(n,false);
        vector<vector<int>>ans;
        func(curr,nums,ans,used);
        return ans;
    }
};