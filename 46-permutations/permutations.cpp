class Solution {
public:
    void func(int start,vector<bool>&empty,vector<int>&arr,vector<vector<int>>&ans,vector<int>&curr){
        if(curr.size()==arr.size()){
            ans.push_back(curr);
            return;
        }
        for(int i=0;i<arr.size();i++){
            if(empty[i]==true){
            curr.push_back(arr[i]);
            empty[i]=false;
            func(i+1,empty,arr,ans,curr);
            curr.pop_back();
            empty[i]=true;}

        }
    }
        vector<vector<int>> permute(vector<int>& nums) {
            int n=nums.size();
        vector<bool>empty(n+1,true);
        vector<int>curr;
        vector<vector<int>>ans;
        func(0,empty,nums,ans,curr);
        return ans;
    }
};