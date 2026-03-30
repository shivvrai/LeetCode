class Solution {
public:
    int trap(vector<int>& arr) {int n=arr.size();
        vector<int>premax(n,-1);int pm=0;
        vector<int>suffmax(n,-1);int sm=0;
        for(int i=0;i<n;i++){
            if(arr[i]>pm)pm=arr[i];
            if(arr[n-i-1]>sm)sm=arr[n-i-1];
            premax[i]=abs(pm);
            
            suffmax[n-i-1]=abs(sm);
        }int sum=0;
        for(int i=0;i<n;i++){
            sum+=min(premax[i],suffmax[i])-arr[i];
        }
        return sum;
    }
};