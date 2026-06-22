class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        int n=arr.size();
        sort(arr.begin(),arr.end());int diff=INT_MAX;int ans=0;
        for(int i=0;i<n;i++){
        if(i>0 and arr[i]==arr[i-1])continue;
        int j=i+1;int k=n-1;
        while(j<k){
            int sum=arr[i]+arr[j]+arr[k];
            int dif=(sum-target);
            if(abs(dif)<diff){diff=abs(dif);ans=sum;}
            if(sum>target){k--;}
            else if (sum<target){j++;}
            else {
                j++;k--;
            }
        }


        }
        return ans;
        
    }
};