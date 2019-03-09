// BFS 
class Solution {
public:
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size(), column = grid[0].size();
    int cnt = 0;
    int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < column; ++j) {
        if (grid[i][j] == '0') {
          continue;
        }
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
                grid[ni][nj] == '0') {
              continue;
            }
            grid[ni][nj] = '0';
            bfs_queue.push(std::make_pair(ni, nj));
          }
          bfs_queue.pop();
        }
        cnt++;
      } 
    }
    return cnt;
  }
};

// DFS
class Solution {
public:
  //int dir[4][2] = {{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
  int dir[5] = {0, 1, 0, -1, 0};
  void dfs(int i, int j, vector<vector<char>>& grid) {    
    int row = grid.size(), col = grid[0].size();
    if (i < 0 || i >= row ||
        j < 0 || j >= col ||
        grid[i][j] == '0'){
      return;
    }
    grid[i][j] = '0';
    for (int d = 0; d < 4; ++d) {
      //dfs(i + dir[d][0], j + dir[d][1], grid);
      dfs(i + dir[d], j + dir[d + 1], grid);
    }
  }
  int numIslands(vector<vector<char>>& grid) {
    if (grid.empty()) return 0;
    int row = grid.size(), col = grid[0].size(), cnt = 0;
    for (int i = 0; i < row; ++i) {
      for (int j = 0; j < col; ++j) {
        if (grid[i][j] == '0') continue;
        dfs(i, j, grid);
        cnt++;
      }
    }
    return cnt;
  }
};