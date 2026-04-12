class Solution {
public:int n=0;
void func(vector<int>&arr,vector<vector<int>>& ans,
        vector<int>& curr,int i){
    ans.push_back(curr);
    for(int j=i;j<n;j++){
        curr.push_back(arr[j]);
        func(arr,ans,curr,j+1);
        curr.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();
        vector<vector<int>>ans;
        vector<int>curr;
        func(nums,ans,curr,0);
        return ans;
    }
};