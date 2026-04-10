class Solution {
public:
    int trap(vector<int>& arr) {
        int leftmax=0,rightmax=0,left=0,right=arr.size()-1;int rainwater=0;
        while(left<right){
                if(arr[left]>=leftmax)leftmax=arr[left];
                if(arr[right]>=rightmax){
                    rightmax=arr[right];
                }

            if(leftmax<=rightmax){
                rainwater+=leftmax-arr[left];left++;
            }else{
                rainwater+=rightmax-arr[right];right--;
            }
        }
        return rainwater;
    }
};