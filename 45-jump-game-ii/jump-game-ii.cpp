class Solution {
public:
    int jump(vector<int>& nums) {
        int curr=0,furthest=0;int ans=0;
        for(int i=0;i<nums.size()-1;i++){
            furthest=max(i+nums[i],furthest);

            if(i==curr){
                ans++;
                curr=furthest;
            }
            
        }
        return ans;
    }
};