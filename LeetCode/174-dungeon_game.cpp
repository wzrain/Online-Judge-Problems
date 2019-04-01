// O(n^2) dp, space reduced to O(n)
class Solution {
public:
  int calculateMinimumHP(vector<vector<int>>& dungeon) {
    int r = dungeon.size(), c = dungeon.front().size();
    //vector<vector<int>> dp(r, vector<int>(c, 0));
    vector<int> dp(c, 0);
    if (dungeon.back().back() < 0) dp[c - 1] = -dungeon.back().back();
    for (int i = r - 1; i >= 0; --i) {
      for (int j = c - 1; j >= 0; --j) {
        if (i == r - 1 && j == c - 1) continue;
        int bt = INT_MAX, rt = INT_MAX;
        if (i < r - 1) bt = dp[j];      // dp[i + 1][j]
        if (j < c - 1) rt = dp[j + 1];  // dp[i][j + 1]
        dp[j] = min(bt, rt) - dungeon[i][j];
        if (dp[j] < 0) dp[j] = 0;
      }
    }
    return dp[0] + 1;
  }
};