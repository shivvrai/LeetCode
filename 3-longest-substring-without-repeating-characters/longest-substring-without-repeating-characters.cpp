class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char,int>mp;int maxi=0,i=0;int n=s.size();
        for(int j=0;j<n;j++){
            if(mp.find(s[j])!=mp.end()){
                i=max(i,mp[s[j]]+1);
            }
            mp[s[j]]=j;
            maxi=max(maxi,j-i+1);
        }
        return maxi;
    }
};