class Solution {
public:
    void func(int start,vector<int>&curr,vector<int>&arr,vector<vector<int>>&ans){
        ans.push_back(curr);
        for(int i=start;i<arr.size();i++){
            if(i>start and arr[i]==arr[i-1])continue;
            curr.push_back(arr[i]);
            func(i+1,curr,arr,ans);
            curr.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<int>curr;
        
        vector<vector<int>>ans;
        func(0,curr,nums,ans);
        return ans;
    }
};