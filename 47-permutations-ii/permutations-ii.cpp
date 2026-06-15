class Solution {
public:
    void func(vector<int>&curr,vector<int>&arr,vector<vector<int>>&ans,vector<bool>&used){
        if(arr.size()==curr.size()){
            ans.push_back(curr);return;
        }
        for(int i=0;i<arr.size();i++){
            if(used[i])continue;
            if(i>0 and arr[i]==arr[i-1] and !used[i-1])continue;
            used[i]=true;
            curr.push_back(arr[i]);
            func(curr,arr,ans,used);
            used[i]=false;
            curr.pop_back();

        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();
        vector<int>curr;
        vector<bool>used(n,false);
        vector<vector<int>>ans;
        func(curr,nums,ans,used);
        return ans;
    }
};