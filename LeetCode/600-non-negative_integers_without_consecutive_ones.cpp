class Solution {
public:
    int findIntegers(int num) {
        bool finish = false;
        int x = num, base = 0;
        while (x) {
            base++;
            x >>= 1;
        }
        vector<int> dp(32, 0);
        dp[0] = 1;
        dp[1] = 2;
        for (int i = 2; i <= base; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        int idx = base, cur = 0, res = 0;
        while(!finish && idx) {
            int msk = 1 << (idx - 1);
            if ((num & msk) && cur) finish = true;
            if (num & msk) res += dp[idx - 1];
            cur = !(!(num & msk));
            idx--;
        }
        if (!finish) res++;
        return res;
    }
};