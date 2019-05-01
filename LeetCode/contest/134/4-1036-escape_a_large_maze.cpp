// Check whether a point is surrounded by a set of points.
// If the number of surrounding points is known and SMALL,
// just search to see whether the bfs process can visit 
// more points than limit.
class Solution {
public:
  struct hashFunc {
    std::size_t operator()(const pair<int, int>& p) const {
      auto h1 = std::hash<int>{}(p.first);
      auto h2 = std::hash<int>{}(p.second);
      return h1 + 0x9e3779b9 + (h2 << 6) + (h2 >> 2);
    }
  };
  bool isEscapePossible(vector<vector<int>>& blocked, vector<int>& source, vector<int>& target) {
    int limit = 20000;
    queue<pair<int, int>> q;
    unordered_set<pair<int, int>, hashFunc> visited;
    int dir[5] = {-1, 0, 1, 0, -1};
    for (auto pt : blocked) {
      visited.insert(make_pair(pt[0], pt[1]));
    }
    q.push(make_pair(source[0], source[1]));
    visited.insert(make_pair(source[0], source[1]));
    int cnt = 0;
    while (!q.empty()) {
      int x = q.front().first, y = q.front().second;
      q.pop();
      cnt++;
      if (cnt > limit) return true;
      for (int d = 0; d < 4; ++d) {
        int nx = x + dir[d], ny = y + dir[d + 1];
        auto coor = make_pair(nx, ny);
        if (nx < 0 || nx >= 1000000 || ny < 0 || ny >= 1000000 || visited.find(coor) != visited.end()) continue;
        visited.insert(coor);
        q.push(coor);
      }
    }
    return false;
  }
};