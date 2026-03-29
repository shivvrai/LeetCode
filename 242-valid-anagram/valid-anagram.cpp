class Solution {
public:
    bool isAnagram(string s, string t) {
        vector<int>freq(256,0);
        if(s.size()!=t.size())return false;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;freq[t[i]]--;

        }
        for(auto i:freq)if(i!=0)return false;
        return true;
        
    }
};