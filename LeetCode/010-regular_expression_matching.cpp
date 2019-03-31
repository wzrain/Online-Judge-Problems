// brute force recursive solution
// updated with memoization
class Solution {
public:
  bool dfs(string& s, string& p, int i, int j, vector<vector<int>>& visited) {
    if (visited[i][j] != -1) return visited[i][j];
    if (j == p.length()) return i == s.length();
    if (i == s.length()) {
      for (int k = j; k < p.length(); ++k) {
        if (p[k] != '*' && (k + 1 >= p.length() || p[k + 1] != '*')) {
          visited[i][j] = 0;
          break;
        }
      }
      if (visited[i][j] == -1) visited[i][j] = 1;
    }
    else if (s[i] == p[j] || p[j] == '.') {
      if (j == p.length() - 1 || p[j + 1] != '*') {
        visited[i][j] = dfs(s, p, i + 1, j + 1, visited);
      }
      else {
        visited[i][j] = dfs(s, p, i, j + 2, visited) || dfs(s, p, i + 1, j, visited);
      }
    }
    else if (j < p.length() - 1 && p[j + 1] == '*') {
      visited[i][j] = dfs(s, p, i, j + 2, visited);
    }
    else visited[i][j] = 0;
    return visited[i][j];
  } 
  bool isMatch(string s, string p) {
    vector<vector<int>> visited(s.length() + 1, vector<int>(p.length() + 1, -1));
    return dfs(s, p, 0, 0, visited);
  }
};

// dp solution
class Solution {
public:
  bool isMatch(string s, string p) {
    int ls = s.length(), lp = p.length();
    vector<vector<int>> dp(ls + 1, vector<int>(lp + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= ls; ++i) dp[i][0] = 0;
    for (int j = 1; j <= lp; ++j) {
      if (j > 1 && p[j - 1] == '*') dp[0][j] = dp[0][j - 2];
    }
    for (int i = 1; i <= ls; ++i) {
      for (int j = 1; j <= lp; ++j) {
        if (s[i - 1] == p[j - 1]) dp[i][j] = dp[i - 1][j - 1];
        else if (p[j - 1] == '.') dp[i][j] = dp[i - 1][j - 1];
        else if (p[j - 1] == '*') {
          // The * here actually creates two "priviledges": match 0 or more than 1 of its preceding character.
          // If we only need to match one preceding character, which means * is redundant,
          // dp[i][j - 1] is actually the equivalent of dp[i - 1][j - 1] in the situation above.
          if (dp[i][j - 2]) dp[i][j] = 1; // no need this a* pattern to match
          else {
            if (p[j - 2] == s[i - 1]) {
              // this a is not the first one that this a* pattern matched
              if (i > 1 && s[i - 1] == s[i - 2] && dp[i - 1][j]) dp[i][j] = 1;
              // this a is the first one that this a* pattern matched
              else if (dp[i - 1][j - 2]) dp[i][j] = 1; // here dp[i - 1][j - 2] == dp[i][j - 1]
            }
            else if (p[j - 2] == '.') {
              // this character is the first one that this .* pattern matched
              if (dp[i - 1][j - 2]) dp[i][j] = 1; // here dp[i - 1][j - 2] == dp[i][j - 1]
              // this character is not the first one that this .* pattern matched
              else if (dp[i - 1][j]) dp[i][j] = 1;
            }
            // the previous part can be simplified as follows:
            /* 
             * if (p[j - 2] == s[i - 1] || p[j - 2] == '.') 
             *   dp[i][j] = dp[i][j - 1] ||  // a*(or .*) pattern match one character(the current one)
             *              dp[i - 1][j];    // a*(or .*) pattern match more than one character
             */ 
          }
        }
      }
    }
    return dp[ls][lp];
  }
};