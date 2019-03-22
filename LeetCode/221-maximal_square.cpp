// original dp solution. O(n^3) time, O(n^2) space
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> rowsum(r, vector<int>(c, 0)), colsum(c, vector<int>(r, 0));
    vector<vector<int>> dp(r, vector<int>(c, 0));
    for (int rr = 0; rr < r; ++rr) {
      for (int cc = 0; cc < c; ++cc) {
        rowsum[rr][cc] = matrix[rr][cc] - '0';
        colsum[cc][rr] = matrix[rr][cc] - '0';
        if (cc) rowsum[rr][cc] += rowsum[rr][cc - 1]; 
        if (rr) colsum[cc][rr] += colsum[cc][rr - 1];
      }
    }
    int maxw = 0;
    for (int w = 0; w < min(r, c); ++w) {
      for (int i = 0; i < r - w; ++i) {
        for (int j = 0; j < c - w; ++j) {
          if (!w) dp[i][j] = matrix[i][j] - '0';
          else {
            if (!dp[i][j]) continue;
            dp[i][j] = 0;
            if (!(matrix[i + w][j + w] - '0')) continue;
            if (rowsum[i + w][j + w - 1] - (j > 0 ? rowsum[i + w][j - 1] : 0) != w) continue;
            if (colsum[j + w][i + w - 1] - (i > 0 ? colsum[j + w][i - 1] : 0) != w) continue;
            dp[i][j] = 1;
          }
          if (dp[i][j] && maxw < w + 1) maxw = w + 1;
        }
      }
    }
    return maxw * maxw;
  }
};

// O(n^2) time, O(n^2) space
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(r, vector<int>(c, 0));
    int maxw = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (matrix[i][j] == '0') {
          dp[i][j] = 0;
          continue;
        }
        dp[i][j] = 1;
        if (j > 0 && i > 0) {
          dp[i][j] += min(dp[i - 1][j - 1], min(dp[i - 1][j], dp[i][j - 1]));
        }
        if (maxw < dp[i][j]) maxw = dp[i][j];
      }
    }
    return maxw * maxw;
  }
};

// reduce the space cost to O(n)
// lines in comments will get rid of one more row
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> dp(2, vector<int>(c, 0));
    //vector<int> dp(c, 0);
    int maxw = 0, tmp = 0, cur = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        //tmp = dp[j];
        if (matrix[i][j] == '0') {
          dp[i & 1][j] = 0;
          //dp[j] = 0;
          //cur = tmp;
          continue;
        }
        dp[i & 1][j] = 1;
        //int val = 1;
        if (j > 0 && i > 0) {
          dp[i & 1][j] += min(dp[(i + 1) & 1][j - 1], min(dp[(i + 1) & 1][j], dp[i & 1][j - 1]));
          //val += min(dp[j], min(cur, dp[j - 1])); 
        }
        //dp[j] = val;
        if (maxw < dp[i & 1][j]) maxw = dp[i & 1][j];
        //if (maxw < dp[j]) maxw = dp[j];
        //cur = tmp;
      }
    }
    return maxw * maxw;
  }
};

// maintain a monotonous queue to record the min value of an interval
// if the min value(stands for how many continuous 1s in each position of the interval)
// is less than the interval length, there will be no more squares
// so shrink the interval to find a new min value
class Solution {
public:
  int maximalSquare(vector<vector<char>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<vector<int>>> dp(r, vector<vector<int>>(r, vector<int>(2, 0)));
    vector<vector<int>> rowsum(r, vector<int>(c, 0));
    
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        rowsum[i][j] = matrix[i][j] - '0';
        if (rowsum[i][j] && j > 0) rowsum[i][j] += rowsum[i][j - 1];
      }
    }
    int maxw = 0;
    for (int j = 0; j < c; ++j) {
      deque<int> dq;
      int head = 0, rear = 0;
      for (int i = 0; i < r; ++i) {
        while (!dq.empty() && rowsum[dq.back()][j] > rowsum[i][j]) dq.pop_back();
        dq.push_back(i);
        rear = i;
        while (rowsum[dq.front()][j] < rear - head + 1) head++;
        while (!dq.empty() && dq.front() < head) dq.pop_front();
        if (maxw < rear - head + 1) maxw = rear - head + 1;
      }
    }
    return maxw * maxw;
  }
};