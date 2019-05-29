class Solution {
public:
  vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
    vector<vector<int>> res;
    unordered_set<int> visited;
    int dir[5] = {-1, 0, 1, 0, -1};
    queue<pair<int, int>> q;
    q.push(make_pair(r0, c0));
    res.push_back({r0, c0});
    visited.insert(c0 + r0 * C);
    while (!q.empty()) {
      int sz = q.size();
      for (int s = 0; s < sz; ++s) {
        int x = q.front().first, y = q.front().second;
        q.pop();
        for (int d = 0; d < 4; ++d) {
          int nx = x + dir[d], ny = y + dir[d + 1];
          if (nx < 0 || nx >= R || ny < 0 || ny >= C || visited.find(ny + nx * C) != visited.end()) continue;
          visited.insert(ny + nx * C);
          q.push(make_pair(nx, ny));
          res.push_back({nx, ny});
        }
      }
    }
    return res;
  }
};