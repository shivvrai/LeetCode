class Solution {
public:int n=0;
void func(vector<vector<int>>&ans,vector<int>&curr,vector<int>&arr,vector<bool>&used){
    if(curr.size()==n){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i])continue;
        used[i]=true;
        curr.push_back(arr[i]);
        func(ans,curr,arr,used);
        curr.pop_back();
        used[i]=false;
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<int>curr;vector<vector<int>>ans;
        vector<bool>used(n,false);
        func(ans,curr,nums,used);
        return ans;
    }
};