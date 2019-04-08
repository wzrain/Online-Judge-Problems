// O(n^2) dp with O(n^2) space
class Solution {
public:
  int numDistinct(string s, string t) {
    if (s.empty() || t.empty()) return 0;
    int sl = s.length(), tl = t.length();
    // dp[i][j] => solution of s.substr(0, i) and t.substr(0, j)
    vector<vector<unsigned int>> dp(sl, vector<unsigned int>(tl, 0));
    for (int j = 0; j < t.length(); ++j) {
      for (int i = 0; i < s.length(); ++i) {
        if (i > 0) dp[i][j] = dp[i - 1][j];
        if (s[i] == t[j]) {
          if (j == 0) dp[i][j]++;  // add one match
          else if (i > 0) dp[i][j] += dp[i - 1][j - 1]; // add t[j] to all the result of 0 to j - 1 before i
        }
      }
    }
    return dp[sl - 1][tl - 1];
  }
};

// Since dp[i][j] only rely on dp[i - 1][j] and dp[i - 1][j - 1], which are
// dp[is][js] where is <= i and js <= j, so it's ok to swap the loop order.
// Note that this is not contradictory to the conclusion we drawn in coin change
// problem. The following loop order, where the dp array is one dimension, is
// unchangable. 
class Solution {
public:
  int numDistinct(string s, string t) {
    if (s.empty() || t.empty()) return 0;
    int sl = s.length(), tl = t.length();
    vector<unsigned int> dp(tl, 0);
    for (int i = 0; i < sl; ++i) {
      for (int j = tl - 1; j >= 0; --j) {
        if (s[i] == t[j]) {
          if (j == 0) dp[j]++;
          else if (i > 0) dp[j] += dp[j - 1];
        }
      }
    }
    return dp[tl - 1];
  }
};

// recursive dp with memoization
class Solution {
public:
  int dfs(string& s, string& t, int i, int j, vector<vector<int>>& dp) {
    if (i == -1 || j == -1) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    dp[i][j] = dfs(s, t, i - 1, j, dp);
    if (s[i] == t[j]) {
      if (j == 0) dp[i][j]++;
      else dp[i][j] += dfs(s, t, i - 1, j - 1, dp);
    }
    return dp[i][j];
  }
  int numDistinct(string s, string t) {
    int sl = s.length(), tl = t.length();
    vector<vector<int>> dp(sl, vector<int>(tl, -1));
    return dfs(s, t, sl - 1, tl - 1, dp);
  }
};