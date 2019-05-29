// dp with O(n^2) space
// dp[i][j] indicates the cost when there are i people and j people go to the first location.
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int len = costs.size();
    vector<vector<int>> dp(len + 1, vector<int>(len + 1, 0));
    for (int i = 1; i <= len; ++i) {
      dp[i][0] = dp[i - 1][0] + costs[i - 1][1];
      for (int j = 1; j < i; ++j) {
        dp[i][j] = min(dp[i - 1][j - 1] + costs[i - 1][0], dp[i - 1][j] + costs[i - 1][1]);
      }
      dp[i][i] = dp[i - 1][i - 1] + costs[i - 1][0];
    }
    return dp[len][len / 2];
  }
};

// O(n) space dp
class Solution {
public:
  int twoCitySchedCost(vector<vector<int>>& costs) {
    int len = costs.size();
    vector<int> dp(len + 1, 0);
    for (int i = 1; i <= len; ++i) {
      dp[i] = dp[i - 1] + costs[i - 1][0];
      for (int j = i - 1; j >= 1; --j) {
        dp[j] = min(dp[j - 1] + costs[i - 1][0], dp[j] + costs[i - 1][1]);
      }
      dp[0] += costs[i - 1][1];
    }
    return dp[len / 2];
  }
};