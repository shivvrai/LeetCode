class Solution {
public:
    vector<int> findAnagrams(string s, string p) {

        vector<int> freq(256,0);
        int count = p.size();
        for(char c : p)
            freq[c]++;
        vector<int> ans;
        int left = 0;
        for(int right = 0; right < s.size(); right++) {
            if(freq[s[right]] > 0)
                count--;
            freq[s[right]]--;
            if(right - left + 1 > p.size()) {
                freq[s[left]]++;
                if(freq[s[left]] > 0)
                    count++;
                left++;
            }
            if(count == 0)
                ans.push_back(left);
        }

        return ans;
    }
};