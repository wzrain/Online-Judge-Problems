class Solution {
public:
  bool dfs(vector<vector<char>>& board, int i, int j, vector<vector<int>>& rf, vector<vector<int>>& cf, vector<vector<int>>& sqf) {
    if (i == 9) return true;
    if (board[i][j] != '.') return dfs(board, i + (j + 1) / 9, (j + 1) % 9, rf, cf, sqf);
    for (int n = 0; n < 9; ++n) {
      if (rf[i][n] || cf[j][n] || sqf[i / 3 * 3 + j / 3][n]) continue;
      board[i][j] = n + '1';
      rf[i][n] = cf[j][n] = sqf[i / 3 * 3 + j / 3][n] = 1;
      if (dfs(board, i + (j + 1) / 9, (j + 1) % 9, rf, cf, sqf)) return true;
      rf[i][n] = cf[j][n] = sqf[i / 3 * 3 + j / 3][n] = 0;
      board[i][j] = '.';
    }
    return false;
  }
  void solveSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rf(9, vector<int>(9, 0));
    vector<vector<int>> cf(9, vector<int>(9, 0));
    vector<vector<int>> sqf(9, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') continue;
        // need to fill the prerequisite first
        int n = board[i][j] - '1';
        rf[i][n] = cf[j][n] = sqf[i / 3 * 3 + j / 3][n] = 1;
      }
    }
    dfs(board, 0, 0, rf, cf, sqf);
  }
};