class Solution {
public:
  struct hashFunc {
    std::size_t operator()(const pair<int, int>& key) const {
      auto h1 = std::hash<int>{}(key.first);
      auto h2 = std::hash<int>{}(key.second);
      return h1 + 0x9e3779b9 + (h2 << 6) + (h2 >> 2);
    }
  };
  struct equalKey {
    bool operator()(const pair<int, int>& s1, const pair<int, int>& s2) const {
      return s1.first == s2.first && s1.second == s2.second;
    }
  };
  bool isRectangleCover(vector<vector<int>>& rectangles) {
    int sqr = 0;
    unordered_set<pair<int, int>, hashFunc, equalKey> corners;
    for (int i = 0; i < rectangles.size(); ++i) {
      sqr += (rectangles[i][2] - rectangles[i][0]) * (rectangles[i][3] - rectangles[i][1]);
      for (int j = 0; j < 4; j += 2) {
        for (int k = 1; k < 4; k += 2) {
          int x = rectangles[i][j], y = rectangles[i][k];
          pair<int, int> pt = make_pair(x, y);
          if (corners.find(pt) == corners.end()) corners.insert(pt);
          else corners.erase(pt);
        }
      }
    }
    if (corners.size() != 4) return false;
    int lx = INT_MAX, rx = 0, by = INT_MAX, ty = 0;
    for (auto p : corners) {
      lx = min(p.first, lx);
      rx = max(p.first, rx);
      by = min(p.second, by);
      ty = max(p.second, ty);
    }
    return sqr == (rx - lx) * (ty - by);
    
  }
};