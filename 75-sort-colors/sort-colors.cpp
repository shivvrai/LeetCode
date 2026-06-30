class Solution {
public:
    void sortColors(vector<int>& arr) {
        int i=-1,j=0,k=arr.size()-1;
        while(j<=k){
        if(arr[j]==0){
            i++;
            swap(arr[i],arr[j]);
            j++;
        }
        else if(arr[j]==1){
            j++;

        }
        else if(arr[j]==2){
            swap(arr[j],arr[k]);
            k--;

        }
        }

    }
};