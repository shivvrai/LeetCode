class Solution {
public:int n=0;
void func(vector<int>&arr,vector<vector<int>>& ans,
        vector<int>& curr,int i){
    if(i==n){
        ans.push_back(curr);return;
    }
    curr.push_back(arr[i]);
    func(arr,ans,curr,i+1);
    curr.pop_back();
    func(arr,ans,curr,i+1);
}
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        func(nums,ans,curr,0);
        return ans;
    }
};