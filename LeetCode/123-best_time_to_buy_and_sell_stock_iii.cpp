// O(n) time, O(n) space
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mn = INT_MAX;
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // get the dp value when there's at most one transaction
        for (int i = 0; i < n; ++i) {
            mn = min(mn, prices[i]);
            dp[i + 1][0] = max(dp[i][0], prices[i] - mn);
        }
        int mx = INT_MIN;
        for (int i = 0; i < n; ++i) {
            dp[i + 1][1] = max(dp[i][1], dp[i + 1][0]);
            if (i > 0) {
                dp[i + 1][1] = max(dp[i + 1][1], prices[i] + mx);
            }
            // here originally we need to go through every
            // previous element to find the best combination
            // (as in the extra loop underneath), but since
            // it actually is an optimal value w.r.t. index
            // from 0 to i, we can just save the optimal
            // value and save one loop.
            mx = max(mx, dp[i][0] - prices[i]);
            // for (int j = 0; j < i; ++j) {
            //     if (prices[j] < prices[i]) {
            //         dp[i + 1][1] = max(dp[i + 1][1], prices[i] - prices[j] + dp[j][0]);
            //     }
            // }
        }
        return dp[n][1];
    }
};

// optimize to O(1) space
// the idea is that we only use the previous dp0 and dp1,
// so only save two variables and calculate dp0 along with
// dp1 in the same loop
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mn = INT_MAX;
        // vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        // for (int i = 0; i < n; ++i) {
        //     mn = min(mn, prices[i]);
        //     dp[i + 1][0] = max(dp[i][0], prices[i] - mn);
        // }
        int mx = INT_MIN;
        int dp0 = 0, dp1 = 0;
        for (int i = 0; i < n; ++i) {
            // dp[i + 1][1] = max(dp[i][1], dp[i + 1][0]);
            dp1 = max(dp1, dp0);
            if (i > 0) {
                // dp[i + 1][1] = max(dp[i + 1][1], prices[i] + mx);
                dp1 = max(dp1, prices[i] + mx);
            }
            // mx = max(mx, dp[i][0] - prices[i]);
            mx = max(mx, dp0 - prices[i]);
            // for (int j = 0; j < i; ++j) {
            //     if (prices[j] < prices[i]) {
            //         dp[i + 1][1] = max(dp[i + 1][1], prices[i] - prices[j] + dp[j][0]);
            //     }
            // }

            // update dp0 at last since the previous
            // calculation needs the "previous" dp0's
            // value
            mn = min(mn, prices[i]);
            dp0 = max(dp0, prices[i] - mn);
        }
        // return dp[n][1];
        return dp1;
    }
};