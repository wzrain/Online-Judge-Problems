// dp[i][j] means the number of rewardable solutions in the first i attendance ended with j (j = A/L/P)
// a0/a1[i][j] are for recording the number of rewardable solutions with 0/1 A's in dp[i][j], which is 
// to be used for calculating dp[i][A]
// onlyl[i] means the number of rewardable solutions in the first i attendance ending with only one L, this is 
// for calculating dp[i][L], because when we add dp[i - 1][A] + dp[i - 1][L] + dp[i - 1][P] to get dp[i][L], the 
// only inrewardable solutions included are the ones ending with only 3 L's (the solution ending with >3 L's 
// are excluded in dp[i - 1][L] already), the number of which is exactly onlyl[i - 2] (which is actually dp[i - 
// 3][A] + dp[i - 3][P], but here we use dp[n - 1] instead of dp[n], so we need "dp[-1][A] + dp[-1][P]" for 
// dp[2][L], that's why a separate onlyl is used and initialized at first to avoid dp[-1] things).
class Solution {
public:
    int checkRecord(int n) {
        // vector<vector<long>> dp(n, vector<long>(3, 0));
        // vector<vector<long>> a0(n, vector<long>(3, 0)), a1(n, vector<long>(3, 0));
        // vector<long> onlyl(n, 0), onlyla0(n, 0), onlyla1(n, 0);
        vector<vector<long>> dp(2, vector<long>(3, 0));
        vector<vector<long>> a0(2, vector<long>(3, 0)), a1(2, vector<long>(3, 0));
        vector<long> onlyl(3, 0), onlyla0(3, 0), onlyla1(3, 0);
        
        dp[0][0] = dp[0][1] = dp[0][2] = 1;
        onlyl[0] = 1;
        
        a1[0][0] = 1;
        a0[0][1] = a0[0][2] = 1;
        onlyla0[0] = 1;
        
        int md = 1e9 + 7;
        for (int i = 1; i < n; ++i) {
            // P
            dp[i & 1][2] = (dp[(i - 1) & 1][0] + dp[(i - 1) & 1][1] + dp[(i - 1) & 1][2]) % md;
            a0[i & 1][2] = (a0[(i - 1) & 1][2] + a0[(i - 1) & 1][1] + a0[(i - 1) & 1][0]) % md;
            a1[i & 1][2] = (a1[(i - 1) & 1][2] + a1[(i - 1) & 1][1] + a1[(i - 1) & 1][0]) % md;
            
            // L
            dp[i & 1][1] = (dp[(i - 1) & 1][0] + dp[(i - 1) & 1][2] + dp[(i - 1) & 1][1]) % md;
            a0[i & 1][1] = (a0[(i - 1) & 1][0] + a0[(i - 1) & 1][2] + a0[(i - 1) & 1][1]) % md;
            a1[i & 1][1] = (a1[(i - 1) & 1][0] + a1[(i - 1) & 1][2] + a1[(i - 1) & 1][1]) % md;
            onlyl[i % 3] = (dp[(i - 1) & 1][0] + dp[(i - 1) & 1][2]) % md;
            onlyla0[i % 3] = (a0[(i - 1) & 1][0] + a0[(i - 1) & 1][2]) % md;
            onlyla1[i % 3] = (a1[(i - 1) & 1][0] + a1[(i - 1) & 1][2]) % md;
            
            if (i > 1) {
                dp[i & 1][1] -= onlyl[(i - 2) % 3];
                a0[i & 1][1] -= onlyla0[(i - 2) % 3];
                a1[i & 1][1] -= onlyla1[(i - 2) % 3];
            }
            
            // A
            a1[i & 1][0] = (a0[(i - 1) & 1][0] + a0[(i - 1) & 1][1] + a0[(i - 1) & 1][2]) % md;
            dp[i & 1][0] = (dp[(i - 1) & 1][0] + dp[(i - 1) & 1][1] + dp[(i - 1) & 1][2] - (a1[(i - 1) & 1][0] + a1[(i - 1) & 1][1] + a1[(i - 1) & 1][2])) % md;
        }
        
        int res = (dp[(n - 1) & 1][0] + dp[(n - 1) & 1][1] + dp[(n - 1) & 1][2]) % md;
        if (res < 0) res += md;
        return res;
    }
};