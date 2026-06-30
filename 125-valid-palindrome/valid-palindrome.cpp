class Solution {
public:
    bool isPalindrome(string s) {
         string S = "";
        for(char ch : s){
            if(isalnum(ch)){
            S += ch;
        }
        }

        transform(S.begin(), S.end(), S.begin(),::tolower);
        string temp = S;

        int l = 0;
        int r = S.size() - 1;
        while(l < r) {
            swap(S[l], S[r]);
            l++;
            r--;
        }

        if(temp == S) {
            return true;
        } else{
            return false;
        }
    }
};