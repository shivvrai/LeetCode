class Solution {
public:
    int characterReplacement(string s, int k) {
        map<char,int>mp;int n=s.size();
        int maxfreq=0;
        int left=0;int maxlength=0;
        for(int right=0;right<n;right++){
            mp[s[right]]++;
            maxfreq=max(maxfreq,mp[s[right]]);
            while(right-left+1 - maxfreq>k){
                mp[s[left]]--;
                left++;
                
            }
            maxlength=max(maxlength,right-left+1);
        }
        return maxlength;
    }
};