// O(n^3) dp
// similar idea as SJTU OJ 1228
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(r, vector<int>(r, 0)), colsum(c, vector<int>(r, 0));
    for (int j = 0; j < c; ++j) {
      for (int i = 0; i < r; ++i) {
        colsum[j][i] = matrix[i][j] - '0';
        if (i > 0) colsum[j][i] += colsum[j][i - 1];
      }
    }
    int sqr = 0;
    for (int k = 0; k < c; ++k) {
      for (int i = 0; i < r; ++i) {
        for (int j = i; j < r; ++j) {
          int s;
          if (!i) s = colsum[k][j];
          else s = colsum[k][j] - colsum[k][i - 1];
          if (s < j - i + 1) {
            dp[i][j] = 0;
            continue;
          }
          dp[i][j]++;
          if (sqr < dp[i][j] * (j - i + 1)) sqr = dp[i][j] * (j - i + 1);
        }
      }
    }
    return sqr;
  }
};

// based on a monotonous stack
// similar idea as 84-largest_rectangle_in_histogram
class Solution {
public:
  int maximalRectangle(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> rowsum(r, vector<int>(c, 0));
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        rowsum[i][j] = matrix[i][j] - '0';
        if (rowsum[i][j] && j > 0) rowsum[i][j] += rowsum[i][j - 1];
      }
    }
    int sqr = 0;
    for (int j = 0; j < c; ++j) {
      vector<pair<int, int>> stk;
      for (int i = 0; i < r; ++i) {
        int l = 0;
        while (!stk.empty() && rowsum[stk.back().first][j] > rowsum[i][j]) {
          int tmp = rowsum[stk.back().first][j] * (i - stk.back().first + stk.back().second);
          if (sqr < tmp) sqr = tmp;
          l += (stk.back().second + 1);
          stk.pop_back();
        }
        stk.push_back(make_pair(i, l));
      }
      while (!stk.empty()) {
        int tmp = rowsum[stk.back().first][j] * (r - stk.back().first + stk.back().second);
        if (sqr < tmp) sqr = tmp;
        stk.pop_back();
      }
    }
    return sqr;
  }
};