class Solution {
public:
    int characterReplacement(string s, int k) {
        vector<int> freq(26, 0);
        int j = 0, maxfreq = 0, ans = 0;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i] - 'A']++;
            maxfreq = max(maxfreq, freq[s[i] - 'A']);

            while ((i - j + 1) - maxfreq > k) {
                freq[s[j] - 'A']--;
                j++;
            }

            ans = max(ans, i - j + 1);
        }

        return ans;
    }
};