class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int xors=0;int n=arr.size();
        for(int i=0;i<n;i++){
            xors=xors^arr[i];
            xors=xors^i;
    }xors=xors^n;
        return xors;
    }
};