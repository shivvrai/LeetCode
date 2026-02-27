class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int n=arr.size();
        int profit=0;
        for(int i=0;i<n-1;i++){
            if(arr[i]<arr[i+1])profit+=abs(arr[i]-arr[i+1]);
        }return profit;
    }
};