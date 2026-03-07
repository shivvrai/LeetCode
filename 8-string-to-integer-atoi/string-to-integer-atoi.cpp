class Solution {
public:
     int helper(int i,string &s,int sign,int ans,int n){
        if(i>=n or !isdigit(s[i]) )return sign*ans;
         long long a= 1ll*ans*10+(s[i]-'0');
         
        
        if(sign*a<=INT_MIN)return INT_MIN;
        if(sign*a>=INT_MAX)return INT_MAX;
        ans=a;
        return helper(i+1,s,sign,ans,n);

    }
    int myAtoi(string s) {
        int i=0,n=s.size();int sign=1;string ans="";
        while(i<n && s[i]==' ')i++;
        if(i<n && (s[i]=='-' || s[i]=='+')){
            if(s[i]=='-') sign=-1;
            i++;
        }
        return helper(i,s,sign,0,n);

    }
};