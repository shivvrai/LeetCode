class Solution {
public:
    string minWindow(string s, string t) {
        int l=0,r=0;

        vector<int>freq(256,0);
        int len=INT_MAX;int ss=0;

        for(auto i:t)freq[i]++;int count=t.size();
        if(t.size()>s.size())return "";
        while(r<s.size()){
            if(freq[s[r]]>0)count--;
            freq[s[r]]--;r++;
            while(count==0){
                if(r-l<len){
                    len=r-l;
                    ss=l;
                }
            freq[s[l]]++;
                if(freq[s[l]]>0)count++;
                l++;

            }
        }
        if(len==INT_MAX)return "";
        return s.substr(ss,len);
    }
};