class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size(), column = grid[0].size();
    int visited[row][column];
    int cnt = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        visited[i][j] = 0;
      }
    }
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (grid[i][j] != '0' && !visited[i][j]) {
          visited[i][j] = 1;
          std::queue<std::pair<int, int>> bfs_queue;
          bfs_queue.push(std::make_pair(i, j));
          while (!bfs_queue.empty()) {
            int ci = bfs_queue.front().first;
            int cj = bfs_queue.front().second;
            for (int d = 0; d < 4; ++d) {
              int ni = ci + dir[d][0];
              int nj = cj + dir[d][1];
              if (ni < 0 ||
                  ni >= row ||
                  nj < 0 ||
                  nj >= column ||
                  visited[ni][nj] ||
                  grid[ni][nj] == '0') {
                continue;
              }
              visited[ni][nj] = 1;
              bfs_queue.push(std::make_pair(ni, nj));
            }
            bfs_queue.pop();
          }
          cnt++;
        }
      } 
    }
    return cnt;
  }
};