class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int> freq(256,-1);
        int cnt=0,maxi=0;int l=0;
        for(int i=0;i<s.size();i++){
            if(freq[s[i]]>=l){
                l=freq[s[i]]+1;
            }
            freq[s[i]]=i;
            cnt=i-l+1;
            maxi=max(maxi,cnt);
        }
        return maxi;
    }
};