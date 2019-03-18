// match subarrays starting from each number in B with kmp
class Solution {
public:
  int findLength(vector<int>& A, vector<int>& B) {
    if (A.empty() || B.empty()) return 0;
    vector<int> next(B.size(), 0);
    int st = 0;
    while (!B.empty()) {
      next[0] = -1;
      for (int i = 1; i < B.size(); ++i) {
        int tmp = next[i - 1];
        while (tmp != -1 && B[i - 1] != B[tmp]) tmp = next[tmp];
        if (tmp == -1) next[i] = 0;
        else next[i] = tmp + 1;
      }
      
      int i = 0, j = 0;
      while (i < A.size()) {
        if (A[i] == B[j]) {
          i++;
          j++;
        }
        else {
          if (st < j) st = j;
          j = next[j];
          if (j == -1) {
            i++;
            j = 0;
          }
        }
        if (j == B.size()) {
          if (st < j) st = j;
          break;
        }
      }
      if (st < j) st = j;
      reverse(B.begin(), B.end());
      B.pop_back();
      reverse(B.begin(), B.end());
    }
    return st;
  }
};

// dp
class Solution {
public:
  int dp[1005][1005];
  int findLength(vector<int>& A, vector<int>& B) {
    for (int i = 0; i < 1005; ++i) {
      for (int j = 0; j < 1005; ++j) {
        dp[i][j] = 0;
      }
    }
    int ml = 0;
    for (int i = 0; i < A.size(); ++i) {
      for (int j = 0; j < B.size(); ++j) {
        if (A[i] == B[j]) {
          if (i > 0 && j > 0) dp[i][j] = dp[i - 1][j - 1] + 1;
          else dp[i][j] = 1;
        } 
        else dp[i][j] = 0;
        if (ml < dp[i][j]) ml = dp[i][j];
      }
    }
    return ml;
  }
};