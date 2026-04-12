class Solution {
public:int n=0;
void func(int index,vector<vector<int>>&ans,vector<int>&curr,vector<int>&arr){
   
        ans.push_back(curr);
    
    for(int i=index;i<n;i++){
        if(i>index and arr[i]==arr[i-1])continue;
        curr.push_back(arr[i]);
        func(i+1,ans,curr,arr);
        curr.pop_back();
        
    }


}
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        vector<int>curr;
        func(0,ans,curr,nums);
        return ans;
    }
};