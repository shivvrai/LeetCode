class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int i=-1,n=arr.size();
        for(int j=0;j<n;j++){
            if(arr[j]!=0){i++;
            swap(arr[j],arr[i]);}
        }
    }
};