class Solution {
public:
    string simplifyPath(string path) {
        vector<string> st;
        string temp="";
        for(int i=0;i<path.size();i++){
            if(path[i]=='/' ){
                if (temp.empty()) continue;
                if(temp==".."){
                    if(!st.empty())st.pop_back();

                }
                else if(temp!=".")st.push_back(temp);
                temp="";

            }
            else{
                temp+=path[i];
            }
        }
        if(temp.size()){
            if(temp==".."){
                    if(!st.empty())st.pop_back();

                }
                else if(temp!=".")st.push_back(temp);
                temp="";
        }
        string ans="";
        for(auto i:st){
            ans=ans+'/'+i;
        }
        return ans.empty() ? "/" : ans;

    }
};