// O(n^2) space dp solution
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l1 + l2 != l3) return false;
    // dp[i][j] indicates whether s1.substr(0, i) and s2.substr(0, j)
    // could interleave to s3.substr(0, i + j)
    vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    dp[0][0] = 1;
    for (int i = 0; i <= l1; ++i) {
      for (int j = 0; j <= l2; ++j) {
        if (i > 0 && s1[i - 1] == s3[i + j - 1]) dp[i][j] = dp[i - 1][j];
        if (j > 0 && s2[j - 1] == s3[i + j - 1]) dp[i][j] = dp[i][j] || dp[i][j - 1];
      }
    }
    return dp[l1][l2];
  }
};

// O(n) space
class Solution {
public:
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l1 + l2 != l3) return false;
    // vector<vector<int>> dp(l1 + 1, vector<int>(l2 + 1, 0));
    vector<int> dp(l2 + 1, 0);
    // dp[0][0] = 1;
    dp[0] = 1;
    for (int i = 0; i <= l1; ++i) {
      for (int j = 0; j <= l2; ++j) {
        if (i == 0 && j == 0) continue;
        if (i == 0 || s1[i - 1] != s3[i + j - 1]) dp[j] = 0; // reset to default
        if (j > 0 && s2[j - 1] == s3[i + j - 1]) dp[j] = dp[j] || dp[j - 1];
      }
    }
    return dp[l2];
  }
};

// bfs solution
// The good thing about bfs here is that we care more about i + j, which is 
// the index of s3 because there has to be at least one match to interleave
// to s3.substr(i + j) to continue search. And every time bfs add one possible
// character, which is exactly add one to the s3 index. 
// Therefore the searching progress is going along the diagonal direction, 
// which could stop early if none of the interleaving in an anti-diagonal line
// is capable of interleave to s3's substring. While the dp solution is going 
// line by line, so every time it has to go through almost every situation
// to draw the conclusion.
class Solution {
public:
  struct hashFunc {
    size_t operator()(const pair<int, int>& p) const {
      auto h1 = std::hash<int>{}(p.first);
      auto h2 = std::hash<int>{}(p.second);
      return h1 + 0x9e3779b9 + (h2 << 6) + (h2 >> 2);
    }
  };
  bool isInterleave(string s1, string s2, string s3) {
    int l1 = s1.length(), l2 = s2.length(), l3 = s3.length();
    if (l1 + l2 != l3) return false;
    queue<pair<int, int>> q;
    unordered_set<pair<int, int>, hashFunc> visited;
    q.push(make_pair(-1, -1));
    while (!q.empty()) {
      int i = q.front().first, j = q.front().second;
      int idx = i + j + 2;
      if (idx == l3) return true;
      pair<int, int> p1 = make_pair(i + 1, j), p2 = make_pair(i , j + 1);
      if (i + 1 < l1 && s1[i + 1] == s3[idx] && visited.find(p1) == visited.end()) {
        q.push(p1);
        visited.insert(p1);
      } 
      if (j + 1 < l2 && s2[j + 1] == s3[idx] && visited.find(p2) == visited.end()) {
        q.push(p2);
        visited.insert(p2);
      }
      q.pop();
    }
    return false;
  }
};