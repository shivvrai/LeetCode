class Solution {
public:
    string minWindow(string s, string t) {
        int count =0;int minlength=INT_MAX;
        map<char,int>mp;
        for( auto i:t){
            mp[i]++;
            count++;
        }
        int i=0;int start=0,end=0;
        for(int j=0;j<s.size();j++){
            if(mp[s[j]]>0)count--;
            mp[s[j]]--;
            while(count==0){
                if(j-i+1<minlength){
                    start=i;
                    end=j;
                    minlength=j-i+1;
                }
                mp[s[i]]++;
                if(mp[s[i]]>0)count++;
                i++;
            }
        }
        return minlength == INT_MAX ? "" : s.substr(start, minlength);
        
    }
};