class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int sum=0,minlen=INT_MAX,j=0;
        for(int i=0;i<arr.size();i++){
            sum+=arr[i];
            while(sum>=target){
                minlen=min(minlen,i-j+1);
                sum-=arr[j];
                j++;

            }

        }
        return minlen==INT_MAX? 0 :minlen;
    }
};