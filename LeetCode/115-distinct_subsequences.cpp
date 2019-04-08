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