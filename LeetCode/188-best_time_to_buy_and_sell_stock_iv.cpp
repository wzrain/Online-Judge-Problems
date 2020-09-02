class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (k >= n / 2) {
            int res = 0;
            for (int i = 0; i < n - 1; ++i) {
                res += max(0, prices[i + 1] - prices[i]);
            }
            return res;
        }
        vector<vector<int>> dp(k + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= k; ++i) {
            int tmp = INT_MIN;
            for (int j = 1; j <= n; ++j) {
                dp[i][j] = max(dp[i][j], max(dp[i][j - 1], dp[i - 1][j]));
                // Instead of running another for loop, just calculate the max value
                // of dp[i - 1][j - 1] - prices[j - 1] for each j in the same loop.
                // The max value of dp[i - 1][l] will be transmitted via the previous
                // comparison to dp[i][j], so there's no worry about the negative value
                // of prices[j - 1] - prices[l], since the result won't be dragged down
                // by a negative diff, since dp[i - 1][l] + prices[j - 1] - prices[l] <=
                // dp[i - 1][l] <= dp[i - 1][j] <= dp[i][j].
                dp[i][j] = max(dp[i][j], prices[j - 1] + tmp);
                tmp = max(tmp, dp[i - 1][j - 1] - prices[j - 1]);              
                // for (int l = 0; l < j - 1; ++l) {
                //     dp[i][j] = max(dp[i][j], dp[i - 1][l] + max(0, prices[j - 1] - prices[l]));
                // }             
            }
        }
        return dp[k][n];
    }
};