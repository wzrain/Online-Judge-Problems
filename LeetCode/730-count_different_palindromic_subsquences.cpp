// when trying to remove duplicate, recount it in the last time it appears
class Solution {
public:
  int dfs(string& s, int i, int j, vector<vector<int>>& dp) {
    if (i > j) return 0;
    if (dp[i][j] != -1) return dp[i][j];
    int res = 0;
    for (int k = 0; k < 4; ++k) {
      int newi = i, newj = j;
      while (newi <= newj && s[newi] - 'a' != k) newi++;
      while (newj >= newi && s[newj] - 'a' != k) newj--;
      if (newi <= newj) res++;
      if (newi < newj) {
        res += (dfs(s, newi + 1, newj - 1, dp) % 1000000007 + 1);
        res %= 1000000007;
      }
    }
    dp[i][j] = res;
    return res;
  }
  int countPalindromicSubsequences(string S) {
    int res = 0, len = S.length();
    vector<vector<int>> dp(len, vector<int>(len, -1));
    return dfs(S, 0, len - 1, dp);
  }
};