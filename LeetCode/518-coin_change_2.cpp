// dp solution
// The loop order here is exactly the opposite of
// of the problem 377-combination_sum_IV.
// dp[j] is a compression of all previously caculated dp[i][j].
// If i loop is the outer loop, the previously calculated dp[i][j]
// will be 0 to the current i. If j loop is the outer loop, the 
// previously calculated i will be all 0 to n - 1.
// This would be fine in the original knapsack problem or 
// 322_coin_change where dp[i][j] stands for an optimal value
// where eventually it will ends at the max/min value. Here 
// dp[i][j] is accumulated iteratively from previously calculated
// values since it stands for a sum. If we do not compress dp[i][j]
// to dp[j] it will still end up with a correct result.
// In another aspect, dp[j] stands for the result of j. If we want
// no duplicate(like here), we calculate the result for EVERY COIN,
// and THEN add up. Otherwise, we first go through all the coins to
// find out EVERY SUM.
class Solution {
public:
  int change(int amount, vector<int>& coins) {
    int n = coins.size();
    //vector<vector<int>> dp(n + 1, vector<int>(amount + 1, 0));
    vector<int> dp(amount + 1, 0);
    //for (int i = 0; i < n; ++i) dp[i][0] = 1;
    dp[0] = 1;
    for (int i = 0; i < n; ++i) {
      for (int j = 1; j <= amount; ++j) {
        if (j < coins[i]) continue;
        dp[j] += dp[j - coins[i]];
      }
    }
    return dp[amount];
  }
};