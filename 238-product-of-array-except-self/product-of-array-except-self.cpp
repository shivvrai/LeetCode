class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suff=nums[nums.size()-1],pre=1;
        vector<int>ans(nums.size(),1);
        for(int i=1;i<nums.size();i++){
            ans[i]=pre*nums[i-1];
            pre*=nums[i-1];
        }
        for(int i=nums.size()-2;i>=0;i--){
            ans[i]*=suff;
            suff*=nums[i];
        }
        return ans;
    }
};