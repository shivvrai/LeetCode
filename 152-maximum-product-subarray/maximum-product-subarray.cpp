class Solution {
public:
    int maxProduct(vector<int>& arr) {
        int maxi=arr[0],mini=arr[0];int res=arr[0];
        for(int i=1;i<arr.size();i++){
            int curr=arr[i];

            if(arr[i]<0)swap(mini,maxi);
            maxi=max(curr,maxi*curr);
            mini=min(curr,mini*curr);
            res=max(res,maxi);
        }
        return res;
    }
};