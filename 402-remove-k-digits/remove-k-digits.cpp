class Solution {
public:
    string removeKdigits(string num, int k) {
        // int size=num.size();
        // if(size<=k)return "0";
        stack<char>st;
        for(auto i:num){
        
        
        while(!st.empty() and k>0 and st.top()>i){st.pop();k--;}
        st.push(i);
        }

        while(k>0 and !st.empty()){
            st.pop();k--;
        }
        if(st.empty())return "0";
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        int i=0;
        reverse(ans.begin(),ans.end());
        string a="";bool zerocame=false;
        for(auto j:ans){
            if(j!='0')break;
            i++;
        }
        a=ans.substr(i);
        return (a==""?"0": a);
    }
};