class Solution {
public:
    bool canJump(vector<int>& nums) {
        int curr=0,maxi=0;
        for(int i=0;i<nums.size();i++){
            if(maxi>=i){
            curr=i+nums[i];
            maxi=max(curr,maxi);
            if(maxi>=nums.size()-1)return true;}
        }
        return false;
    }
};