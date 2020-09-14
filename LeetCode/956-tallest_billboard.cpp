// Think in a subproblem manner. If another rod k comes,
// we need to know that in the previous rods what is the
// maximum sum if two sums have a difference of k, so 
// that we can form a equal pair of sum.
// dp[i][j] means in rods [0, i - 1], the maximum value 
// of the larger sum of a pair with a difference of j. So
// the result is dp[n][0]. for a difference j, rods[i - 1]
// can influence dp[i][j + rods[i - 1]] and dp[i][abs(j - rods[i - 1])].
class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) cnt += rods[i];
        int lim = cnt / 2;
        vector<vector<int>> dp(2, vector<int>(lim + 1, -1));
        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            int cur = rods[i - 1];
            // We need to first copy dp[i - 1][j] to
            // dp[i][j], and later directly compare
            // with dp[i][j], since dp[i][j] might be
            // modified by several update in the for-j
            // loop and we need to find a max among
            // those update.
            for (int j = 0; j <= lim; ++j) {
                dp[i & 1][j] = max(dp[(i - 1) & 1][j], dp[i & 1][j]);
            }
            for (int j = 0; j <= lim; ++j) {
                if (dp[(i - 1) & 1][j] == -1) continue;
                if (j + cur <= lim) dp[i & 1][j + cur] = max(dp[(i - 1) & 1][j] + cur, dp[i & 1][j + cur]);
                if (abs(j - cur) <= lim) dp[i & 1][abs(j - cur)] = max(j > cur ? dp[(i - 1) & 1][j] : dp[(i - 1) & 1][j] + cur - j, dp[i & 1][abs(j - cur)]);
            }
        }
        return dp[n & 1][0];
    }
};