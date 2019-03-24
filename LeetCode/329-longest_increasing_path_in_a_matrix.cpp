class Solution {
public:
  int dir[5] = {-1, 0, 1, 0, -1};
  int dfs(vector<vector<int>>& matrix, int i, int j, vector<vector<int>>& visited) {
    if (visited[i][j] > 0) return visited[i][j];
    int maxl = 1;
    for (int d = 0; d < 4; ++d) {
      int ni = i + dir[d], nj = j + dir[d + 1];
      if (ni < 0 || ni >= matrix.size() || 
          nj < 0 || nj >= matrix[0].size() || 
          matrix[ni][nj] <= matrix[i][j]) { 
        continue;
      }
      int tmp = 1 + dfs(matrix, ni, nj, visited);
      maxl = max(maxl, tmp);
    }
    visited[i][j] = maxl;
    return maxl;
  }
  int longestIncreasingPath(vector<vector<int>>& matrix) {
    if (matrix.empty()) return 0;
    int r = matrix.size(), c = matrix[0].size();
    vector<vector<int>> visited(r, vector<int>(c, 0));
    int maxlen = 0;
    for (int i = 0; i < r; ++i) {
      for (int j = 0; j < c; ++j) {
        if (visited[i][j] == 0) dfs(matrix, i, j, visited); // a bit faster than !visited[i][j]
        if (maxlen < visited[i][j]) maxlen = visited[i][j];
      }
    }
    return maxlen;
  }
};