class Solution {
public:
    bool ispalindrome(string s,int l,int r){
        while(l<r){
            if(s[l++]!=s[r--])return false;
        }
        return true;
    }
    void func(int start,string& s,vector<string> curr,vector<vector<string>>& ans){
        if(start==s.length()){
            ans.push_back(curr);
            return;
        }
        for(int end=start+1;end<=s.size();end++){
            if(ispalindrome(s,start,end-1)){
                curr.push_back(s.substr(start,end-start));
                func(end,s,curr,ans);
                curr.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> curr;
        func(0,s,curr,ans);
        return ans;
    }
};