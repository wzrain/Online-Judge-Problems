// brute force recursive solution
class Solution {
public:
  bool isMatch(string s, string p) {
    if (p.empty()) return s.empty();
    if (s.empty()) {
      for (int i = 0; i < p.length(); ++i) {
        if (p[i] != '*' && (i + 1 >= p.length() || p[i + 1] != '*')) return false;
      }
      return true;
    }
    if (s[0] == p[0] || p[0] == '.') {
      if (p.length() <= 1 || p[1] != '*') {
        return isMatch(s.substr(1, s.length() - 1), p.substr(1, p.length() - 1));
      } 
      else {
        if (isMatch(s, p.substr(2, p.length() - 2))) return true;
        for (int i = 0; i < s.length(); ++i) {
          if (p[0] != '.' && s[i] != p[0]) break;
          if (isMatch(s.substr(i + 1, s.length() - i - 1), p.substr(2, p.length() - 2))) return true;
        }
        return false;
        // this situation can be simplified as follows:
        /*
         * return isMatch(s, p.substr(2, p.length() - 2)) ||
         *        isMatch(s.substr(1, s.length() - 1), p)    // The current character is matched by the a*(or .*) pattern.
         *                                                   // Since this pattern can be ignored using the previous line,
         *                                                   // we can just find out whether there is more to match 
         *                                                   // by seeing where this pattern will be ignored.
         */
      }           
    }
    else if (p.length() > 1 && p[1] == '*') return isMatch(s, p.substr(2, p.length() - 2));
    return false;
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