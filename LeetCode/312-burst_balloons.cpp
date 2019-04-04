class Solution {
public:
  int maxCoins(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
    for (int i = 1; i <= n; ++i) dp[i][i] = nums[i - 1];
    dp[0][0] = dp[n + 1][n + 1] = 1;
    for (int w = 2; w < n + 2; ++w) {
      for (int i = 0; i <= n + 1 - w; ++i) {
        for (int j = i + 1; j < i + w; ++j) {
          int tmp = dp[i][i] * dp[i + w][i + w] * dp[j][j] + dp[i][j] + dp[j][i + w];
          if (dp[i][i + w] < tmp) dp[i][i + w] = tmp;
        }
      }
    }
    return dp[0][n + 1];
  }
};