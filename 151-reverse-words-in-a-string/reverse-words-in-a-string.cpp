class Solution {
public:
    string reverseWords(string s) {
        vector<string>arr;int n=s.size();
        int i=0,l=0,r=0;
        while(i<n){
            string ans="";
            while(s[i]==' ' and i<n){
                i++;
            }
            l=i;
            while(s[i]!=' ' and i<n){
                i++;
            }
            r=i;
            ans=s.substr(l,r-l);
            if(ans.size()!=0)
            arr.push_back(ans);
        }string ok="";
        if(arr.size()!=0){
         ok=arr[arr.size()-1];
        for(int i=arr.size()-2;i>=0;i--){
            ok=ok+" "+arr[i];
        }}
        return ok;
    }
};