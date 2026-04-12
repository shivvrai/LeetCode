class Solution {
public:int n=0;
    void func(vector<vector<int>>&ans,vector<int>&curr,vector<int>&arr,vector<bool>&used){
    if(curr.size()==n){
        ans.push_back(curr);
        return;
    }
    for(int i=0;i<n;i++){
        if(used[i])continue;
        if(i>0 and arr[i]==arr[i-1] and !used[i-1])continue;

        used[i]=true;
        curr.push_back(arr[i]);
        func(ans,curr,arr,used);
        curr.pop_back();
        used[i]=false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>curr;vector<vector<int>>ans;
        vector<bool>used(n,false);
        func(ans,curr,nums,used);
        return ans;
    }
};