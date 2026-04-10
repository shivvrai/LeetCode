class Solution {
public:
    string longestPalindrome(string s) {
        if(s.empty()) return "";
        int start=0;
        int end=0;
        for(int i=0;i<s.size();i++){
            int odd=func(s,i,i);
            int even=func(s,i,i+1);
            int maxlen=max(odd,even);
            if(maxlen > end- start){
                start=i-(maxlen-1)/2;
                end=i+(maxlen)/2;
            }
        }
            return s.substr(start,end-start+1);

    }
    private:
    int func(string &s,int left,int right){
        int count=0;
        while(left>=0 and right<s.size() and s[left]==s[right]){
            left--;
            right++;
            count++;
        }
        return right-left-1;
    }
    
};