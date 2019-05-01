// bfs solution
class Solution {
public:
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    int ic = grid[r0][c0], dir[5] = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(r0, c0));
    unordered_set<int> visited;
    visited.insert(c0 + r0 * grid[0].size());
    vector<pair<int, int>> res;
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      for (int d = 0; d < 4; ++d) {
        int nx = x + dir[d], ny = y + dir[d + 1];
        // On the border of the whole board. No doubt a border point.
        if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) {
          grid[x][y] = color;
          continue;
        }
        if(visited.find(ny + nx * grid[0].size()) != visited.end()) continue;
        // Not a point of the region => at the border.
        // Note that the three ifs cannot be changed cuz the previous if
        // eliminates the situation where (nx, ny) is already a border point
        // which has been colored.
        if (grid[nx][ny] != ic) {
          grid[x][y] = color;
          continue;
        }
        q.push(make_pair(nx, ny));
        visited.insert(ny + nx * grid[0].size());
      }
    }
    return grid;
  }
};

// dfs solution
class Solution {
public:
  void dfs(vector<vector<int>>& grid, int x, int y, int ic, int color, vector<int>& dir, unordered_set<int>& visited) {
    for (int d = 0; d < 4; ++d) {
      int nx = x + dir[d], ny = y + dir[d + 1];
      if (nx < 0 || nx >= grid.size() || ny < 0 || ny >= grid[0].size()) {
        grid[x][y] = color;
        continue;
      }
      if(visited.find(ny + nx * grid[0].size()) != visited.end()) continue;
      if (grid[nx][ny] != ic) {
        grid[x][y] = color;
        continue;
      }
      visited.insert(ny + nx * grid[0].size());
      dfs(grid, nx, ny, ic, color, dir, visited);
    }
  }
  vector<vector<int>> colorBorder(vector<vector<int>>& grid, int r0, int c0, int color) {
    int ic = grid[r0][c0];
    vector<int> dir = {-1, 0, 1, 0, -1};
    unordered_set<int> visited;
    visited.insert(c0 + r0 * grid[0].size());
    dfs(grid, r0, c0, ic, color, dir, visited);
    return grid;
  }
};