class Solution {
public:
    const int MOD = 1e9 + 7;
    int concatenatedBinary(int n) {
        long res = 0;
        int digs = 0;

        for (int i = 1; i <= n; i++) {
            if ((i & (i - 1)) == 0) digs++;    
            res = ((res << digs) % MOD + i) % MOD;
        }
        return res;
    }
};