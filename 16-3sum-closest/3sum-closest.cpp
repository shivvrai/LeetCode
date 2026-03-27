class Solution {
public:
    int threeSumClosest(vector<int>& arr, int target) {
        //  vector<vector<int>>ans;
        int n=arr.size();
int res=INT_MAX;int ans=0;
        sort(arr.begin(),arr.end());
        
        for(int i=0;i<n-2;i++){
             if(i > 0 && arr[i] == arr[i - 1]) continue;
            int j=i+1;int k=n-1;
            
                while(j<k){
                    int sum=arr[i]+arr[j]+arr[k];
                    int change=res;
                    if(sum>target)k--;
                    else j++;
                 res=min(abs(sum-target),res);
                 if(res!=change)ans=sum;
                 

                }
                
            
        }
        return ans;
    }
};