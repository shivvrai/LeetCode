class Solution {
public:
    vector<int> productExceptSelf(vector<int>& arr) {
              vector<int>ans(arr.size());
              int pre=1,suff=1;
            int n=arr.size();
            for(int i=0;i<n;i++){
                ans[i]=pre;
                pre*=arr[i];
            }
            for(int i=n-1;i>=0;i--){
                ans[i]*=suff;
                suff*=arr[i];
            }
            return ans;
    }
};