class Solution {
public:
    int subarraySum(vector<int>& arr, int k) {
map<int,int> mp;int n=arr.size();int cnt=0,sum=0;mp[0]=1;

for(int i=0;i<n;i++){
    sum+=arr[i];
    int rem=sum-k;
    if(mp.find(rem)!=mp.end()){
       cnt+=mp[rem];
    }
    mp[sum]++;

}
return cnt;
    }
};