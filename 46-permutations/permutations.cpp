class Solution {
public:
    void func(vector<int>&arr, vector<int>&curr,vector<vector<int>>& ans, vector<bool>&used){
        if(curr.size()==arr.size()){ans.push_back(curr);return;}

        for(int i=0;i<arr.size();i++){
            if(used[i])continue;
            used[i]=true;
            curr.push_back(arr[i]);
            func(arr,curr,ans,used);
            curr.pop_back();
            used[i]=false;
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool>used(nums.size(),false);
        vector<vector<int>>ans;
        vector<int>curr;
        func(nums,curr,ans,used);
        return ans;
        
    }
};