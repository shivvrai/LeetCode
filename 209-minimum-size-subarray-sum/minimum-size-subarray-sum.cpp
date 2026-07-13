class Solution {
public:
    int minSubArrayLen(int target, vector<int>& arr) {
        int left=0,right=0,minilen=INT_MAX,sum=0;
        if(!arr.size())return 0;
        for(right=0;right<arr.size();right++){
            sum+=arr[right];
            while(sum>=target){
                minilen=min(minilen,right-left+1);
                sum-=arr[left];
                left++;

            }
        }
        return minilen==INT_MAX?0:minilen;
    }
};