// In bfs or dfs, the visited array is a signal for those positions
// which do not need to be searched. If there are some other features
// about this information, we don't need a visited array, like the value
// of positions that do not need to be searched is unique(for example, we
// can modify the value of searched positions to invalid values to make
// them unreachable. Here the search-free positions all have a features
// that they are not the first positions of a battleship, which means either
// its above or left position is X.)
class Solution {
public:
  int countBattleships(vector<vector<char>>& board) {
    if (board.empty()) return 0;
    int cnt = 0;
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board.front().size(); ++j) {
        if (board[i][j] == '.') continue;
        if (j > 0 && board[i][j - 1] == 'X') continue;
        if (i > 0 && board[i - 1][j] == 'X') continue;
        cnt++;
      }
    }
    return cnt;
  }
};