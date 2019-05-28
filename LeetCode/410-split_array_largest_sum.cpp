// dp with memoization
// focus on the first split position and let the code do the work
class Solution {
public:
  long dfs(int n, int m, int idx, vector<vector<long>>& dp) {
    if (m > n - idx) return LONG_MAX;
    if (dp[idx][m] != LONG_MAX) return dp[idx][m];
    for (int i = idx; i < n; ++i) {
      long si = dp[idx][1] - (i == n - 1 ? 0 : dp[i + 1][1]); // sum from idx to i
      if (si > dp[idx][m]) break; // Pruning: the final result (dp[idx][m]) would be no larger than si.
      long tmp = dfs(n, m - 1, i + 1, dp);
      dp[idx][m] = min(dp[idx][m], max(si, tmp));
    }
    return dp[idx][m];
  }
  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<vector<long>> dp(n, vector<long>(m + 1, LONG_MAX));
    dp[n - 1][1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      dp[i][1] = dp[i + 1][1] + nums[i];
    }
    return dfs(n, m, 0, dp);
  }
};