class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n=s.size();
        if(n==0)return 0;
        int i=0,j=0;
        vector<int> freq(256, -1);
        int cnt=0,maxi=INT_MIN;
        while(j<n){
            if(freq[s[j]]!=-1){
                i=max(i,freq[s[j]]+1);
            }
            cnt=j-i+1;
            freq[s[j]]=j;
            maxi=max(maxi,cnt);j++;
        }
        return maxi;
    }
};