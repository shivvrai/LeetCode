class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int i=0,len=INT_MAX,n=nums.size(),sum=0;
        for(int j=0;j<n;j++){
            sum+=nums[j];
            while(sum>=target){
                sum-=nums[i];
                len=min(len,j-i+1);
                i++;
            }

        }if(len==INT_MAX)return 0; return len;
    }
};