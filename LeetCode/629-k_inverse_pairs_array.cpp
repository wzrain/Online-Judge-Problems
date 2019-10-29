// dp(i, j) = dp(i - 1, j)            // i is put in the last position
//          + dp(i - 1, j - 1)        // i is ahead of one previous number
//          + dp(i - 1, j - 2)        // i is ahead of two previous numbers
//          ...
//          + dp(i - 1, j - (i - 1))  // i is the first number
class Solution {
public:
  int kInversePairs(int n, int k) {
    std::vector<vector<int>> dp(n + 1, std::vector<int>(k + 1, 0));
    for (int i = 1; i <= n; ++i) {
      dp[i][0] = 1;
    }
    for (int i = 2; i <= n; ++i) {
      for (int j = 1; j <= min(k, i * (i - 1) / 2); ++j) {
        dp[i][j] = 
          (dp[i][j - 1] + dp[i - 1][j] - (j >= i ? dp[i - 1][j - i] : 0)) % 1000000007;
        if (dp[i][j] < 0) {
          dp[i][j] += 1000000007;
        }
      }
    }
    return dp[n][k];
  }
};