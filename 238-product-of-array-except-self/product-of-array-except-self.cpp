class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int suff=1,pre=1,n=nums.size();vector<int>ans(n,1);
        for(int i=0;i<n;i++){
            ans[i]=pre;
            pre=pre*nums[i];
        }
        for(int i=n-1;i>=0;i--){
            ans[i]=ans[i]*suff;
            suff=suff*nums[i];
        }
        return ans;
    }
};