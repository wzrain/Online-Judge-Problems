// O(n^2) time dp solution, space reduced to O(n)
class Solution {
public:
  bool isMatch(string s, string p) {
    int sl = s.length(), pl = p.length();
    //vector<vector<int>> dp(sl + 1, vector<int>(pl + 1, 0));
    vector<vector<int>> dp(2, vector<int>(pl + 1, 0));
    dp[0][0] = 1;
    for (int j = 1; j <= pl; ++j) {
      if (p[j - 1] == '*') dp[0][j] = dp[0][j - 1];
    }
    for (int i = 1; i <= sl; ++i) {
      dp[i & 1][0] = 0; // In O(n^2) space, dp[i][0](i > 0) is default 0 and never modified.
                        // But in O(n) space the dp vector is used recurrently, and dp[0][0]
                        // will be visited regularly, so need to set it to 0 every loop.
      for (int j = 1; j <= pl; ++j) {
        if (s[i - 1] == p[j - 1] || p[j - 1] == '?') dp[i & 1][j] = dp[(i - 1) & 1][j - 1];
        else if (p[j - 1] == '*') {
          dp[i & 1][j] = dp[(i - 1) & 1][j] ||   // dp[i - 1][j] - match more than one character
                     dp[i & 1][j - 1] ||         // dp[i][j - 1] - match no character
                     dp[(i - 1) & 1][j - 1];     // dp[i - 1][j - 1] - match one character
        }
        else dp[i & 1][j] = 0; // In O(n^2) space dp[i][j] is default as 0. When the dp vector 
                               // is regularly used there is no DEFAULT.
      }
    }
    return dp[sl & 1][pl];
  }
};

// recursion with memoization
// similar idea with dp, but visited[i][j] records
// whether s.substr(i) and p.substr(j) matches, 
// which is different from dp.
class Solution {
public:
  bool dfs(string& s, string& p, int i, int j, vector<vector<int>>& visited) {
    if (visited[i][j] != -1) return visited[i][j];
    if (j == p.length()) return i == s.length();
    if (i == s.length()) {
      for (int k = j; k < p.length(); ++k) {
        if (p[k] != '*') {
          visited[i][j] = 0;
          break;
        }
      }
      if (visited[i][j] == -1) visited[i][j] = 1;
    }
    else if (s[i] == p[j] || p[j] == '?') {
      visited[i][j] = dfs(s, p, i + 1, j + 1, visited);
    }
    else if (p[j] == '*') {
      visited[i][j] = dfs(s, p, i, j + 1, visited) || dfs(s, p, i + 1, j, visited);
    }
    else visited[i][j] = 0;
    return visited[i][j];
  }
  bool isMatch(string s, string p) {
    vector<vector<int>> visited(s.length() + 1, vector<int>(p.length() + 1, -1));
    return dfs(s, p, 0, 0, visited);
  }
};