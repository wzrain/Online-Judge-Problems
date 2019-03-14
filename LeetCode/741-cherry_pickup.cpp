class Solution_n3space {
public:
  int dp[120][55][55];
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    for (int i = 0; i < 120; ++i) {
      for (int j = 0; j < 55; ++j) {
        for (int k = 0; k < 55; ++k) {
          dp[i][j][k] = -1;
        }
      }
    }
    dp[0][0][0] = 0;
    for (int s = 0; s < 2 * n - 1; ++s) {
      for (int i1 = 0; i1 < n && i1 <= s; ++i1) {
        for (int i2 = 0; i2 < n && i2 <= s; ++i2) {
          int j1 = s - i1, j2 = s - i2;
          if (j1 >= n || j2 >= n) continue;
          if (dp[s][i1][i2] > 0 || grid[i1][j1] == -1 || grid[i2][j2] == -1) continue;
          int tmp = dp[s][i1][i2];
          if (i1 > 0 && j2 > 0) tmp = max(tmp, dp[s - 1][i1 - 1][i2]);
          if (i2 > 0 && j1 > 0) tmp = max(tmp, dp[s - 1][i1][i2 - 1]);
          if (j2 > 0 && j1 > 0) tmp = max(tmp, dp[s - 1][i1][i2]);
          if (i1 > 0 && i2 > 0) tmp = max(tmp, dp[s - 1][i1 - 1][i2 - 1]);
          if (tmp < 0) continue;
          int cur = tmp + grid[i1][j1];
          if (i1 != i2) cur += grid[i2][j2];
          dp[s][i1][i2] = cur;
        }
      }
    }
    return dp[2 * n - 2][n - 1][n - 1] < 0 ? 0 : dp[2 * n - 2][n - 1][n - 1] ;
  }
};

class Solution_n2space {
public:
  int dp[55][55];
  int cherryPickup(vector<vector<int>>& grid) {
    int n = grid.size();
    if (n == 0) return 0;
    for (int j = 0; j < 55; ++j) {
      for (int k = 0; k < 55; ++k) {
        dp[j][k] = -1;
      }
    }
    dp[0][0] = 0;
    for (int s = 0; s < 2 * n - 1; ++s) {
      for (int i1 = n - 1; i1 >= 0 ; --i1) {
        for (int i2 = n - 1; i2 >= 0; --i2) {
          int j1 = s - i1, j2 = s - i2;
          if (j1 >= n || j2 >= n || j1 < 0 || j2 < 0) continue;
          if (grid[i1][j1] == -1 || grid[i2][j2] == -1) {
            dp[i1][i2] = -1;
            continue;
          }
          int tmp = dp[i1][i2];
          if (i1 > 0 && j2 > 0) tmp = max(tmp, dp[i1 - 1][i2]);
          if (i2 > 0 && j1 > 0) tmp = max(tmp, dp[i1][i2 - 1]);
          //if (j2 > 0 && j1 > 0) tmp = max(tmp, dp[i1][i2]);
          if (i1 > 0 && i2 > 0) tmp = max(tmp, dp[i1 - 1][i2 - 1]);
          if (tmp < 0) continue;
          int cur = tmp + grid[i1][j1];
          if (i1 != i2) cur += grid[i2][j2];
          dp[i1][i2] = cur;
        }
      }
    }
    return dp[n - 1][n - 1] < 0 ? 0 : dp[n - 1][n - 1] ;
  }
};