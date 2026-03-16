class Solution {
public:
    int longestOnes(vector<int>& arr, int k) {
        int l=0,r=0,zeros=0,maxi=0;int n=arr.size();
        while(r<n){
            if(arr[r]==0)zeros++;
            if(zeros>k){
                if(arr[l]==0)zeros--;
                l++;
    
            }
            else{
                maxi=max(maxi,r-l+1);
                
            }
            r++;
        }return maxi;
    }
};