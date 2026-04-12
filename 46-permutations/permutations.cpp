class Solution {
public:int n=0;
    void func(int i,vector<vector<int>>&ans,vector<int>&arr){
        if(i==n){
            ans.push_back(arr);return;
        }
        for(int j=i;j<n;j++){
            swap(arr[i],arr[j]);
            func(i+1,ans,arr);
            swap(arr[i],arr[j]);

        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        func(0,ans,nums);
        return ans;
    }
};