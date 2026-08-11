class Solution {
public:
    int lengthOfLongestSubstring(string s) {
    int left=0;
    map<char,int>mp;int len=0;
    for(int right=0;right<s.size();right++){
        if(mp.find(s[right])!=mp.end()){
            left=max(mp[s[right]]+1,left);
            
        }
        mp[s[right]]=right;
        len=max(right-left+1,len);
    }
    return len;
    }
};