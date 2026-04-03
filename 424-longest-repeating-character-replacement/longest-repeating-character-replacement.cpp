class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxfreq=0;
        map<int,int>freq;int len=0;
        int i=0;
        for(int j=0;j<s.size();j++){
            freq[s[j]]++;
            maxfreq=max(maxfreq,freq[s[j]]);
            while(j-i+1 - maxfreq > k){
                freq[s[i]]--;
                i++;
                
            }
            len=max(len,j-i+1);

        }
        return len;
    }
};