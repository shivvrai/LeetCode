class Solution {
public:
    int characterReplacement(string arr, int k) {
        int maxfreq=0;map<int,int>freq;
        int left=0;int maxlen=0;int n=arr.size();
        for(int right=0;right<n;right++){
            freq[arr[right]]++;
            if(freq[arr[right]]>maxfreq)maxfreq=freq[arr[right]];
            int length=right-left+1;
            while(-maxfreq+length>k){
                freq[arr[left]]--;
                left++;
                length=right-left+1;
            }
            maxlen=max(length,maxlen);
        }
        return maxlen;
    }
};