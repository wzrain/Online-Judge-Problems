class Solution {
public:
  bool isValidSudoku(vector<vector<char>>& board) {
    vector<vector<int>> rf(9, vector<int>(9, 0)), cf(9, vector<int>(9, 0)), sqf(9, vector<int>(9, 0));
    for (int i = 0; i < 9; ++i) {
      for (int j = 0; j < 9; ++j) {
        if (board[i][j] == '.') continue;
        int n = board[i][j] - '1';
        if (rf[i][n] || cf[j][n] || sqf[i / 3 * 3 + j / 3][n]) return false;
        rf[i][n] = cf[j][n] = sqf[i / 3 * 3 + j / 3][n] = 1;
      }
    }
    return true;
  }
};