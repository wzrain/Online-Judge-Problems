// dp solution
class Solution {
public:
  int coinChange(vector<int>& coins, int amount) {
    vector<int> dp(amount + 1, INT_MAX - 1);
    dp[0] = 0;
    for (int j = 1; j <= amount; ++j) {
      for (int i = 0; i < coins.size(); ++i) { // loop order changable
        if (j < coins[i]) continue;
        if (dp[j] > dp[j - coins[i]] + 1) dp[j] = dp[j - coins[i]] + 1;
      }
    }
    return dp[amount] == INT_MAX - 1 ? -1 : dp[amount];
  }
};

// dfs with memoization
class Solution {
public:
  int dfs(vector<int>& coins, int tgt, vector<int>& cnt) {
    if (cnt[tgt] != INT_MIN) return cnt[tgt];
    if (!tgt) return 0;
    int res = INT_MAX;
    for (int i = 0; i < coins.size(); ++i) {
      if (tgt < coins[i]) continue;
      int tmp = dfs(coins, tgt - coins[i], cnt);
      if (tmp >= 0) res = min(res, tmp + 1);
    }
    cnt[tgt] = res == INT_MAX ? -1 : res;
    return cnt[tgt];
  }
  int coinChange(vector<int>& coins, int amount) {
    vector<int> cnt(amount + 1, INT_MIN);
    return dfs(coins, amount, cnt);
  }
};