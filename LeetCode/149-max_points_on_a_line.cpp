/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
public:
  struct line {
    int a, b, c;
    line(int aa = 0, int bb = 0, int cc = 0) : a(aa), b(bb), c(cc) {}
  };
  struct hashFunc {
    std::size_t operator()(const line& p) const {
      auto h1 = std::hash<int>{}(p.a);
      auto h2 = std::hash<int>{}(p.b >> 1);
      auto h3 = std::hash<int>{}(p.c >> 1);
      return h1 ^ (h2 << 1) ^ (h3); 
    }
  };
  struct equalKey {
    bool operator()(const line& s1, const line& s2) const {
      return s1.a == s2.a && s1.b == s2.b && s1.c == s2.c;
    }
  };
  struct hashFunc2 {
    std::size_t operator()(const Point& p) const {
      auto h1 = std::hash<int>{}(p.x);
      auto h2 = std::hash<int>{}(p.y);
      return h1 + 0x9e3779b9 + (h2 << 6) + (h2 >> 2); 
    }
  };
  struct equalKey2 {
    bool operator()(const Point& s1, const Point& s2) const {
      return s1.x == s2.x && s1.y == s2.y;
    }
  };
  
  int findGCD(int x, int y) {
    if (x < y) return findGCD(y, x);
    if (y == 0) return x;
    return findGCD(y, x % y);
  }
  int maxPoints(vector<Point>& points) {
    unordered_map<line, int, hashFunc, equalKey> mp;
    unordered_map<line, unordered_set<Point, hashFunc2, equalKey2>, hashFunc, equalKey> pts;
    unordered_map<Point, int, hashFunc2, equalKey2> cnt;
    int mxd = 0;
    for (int i = 0; i < points.size(); ++i) {
      cnt[points[i]]++;
      if (mxd < cnt[points[i]]) mxd = cnt[points[i]];
    }
    int mx = -1;
    for (int i = 0; i < points.size(); ++i) {
      for (int j = i + 1; j < points.size(); ++j) {
        long a, b, c;
        long x1 = points[i].x, y1 = points[i].y;
        long x2 = points[j].x, y2 = points[j].y;
        if (x1 == x2 && y1 == y2) continue;
        if (x1 == x2) {
          b = 0;
          a = 1;
          c = x1;
        }
        else if (y1 == y2) {
          a = 0;
          b = 1;
          c = y2;
        }
        else {
          a = y1 - y2;
          b = x2 - x1;
          c = x2 * y1 - x1 * y2;
          int gcd = findGCD(findGCD(abs(a), abs(b)), abs(c));
          a = a / gcd;
          b = b / gcd;
          c = c / gcd;
        }
        line ln(a, b, c);
        if (mp.find(ln) != mp.end() && 
            pts[ln].find(points[j]) != pts[ln].end() &&
            pts[ln].find(points[i]) != pts[ln].end()) {
          continue;
        }
        if (mp.find(ln) == mp.end()) {
          mp[ln] = cnt[points[i]] + cnt[points[j]];
          pts[ln].insert(points[i]);
          pts[ln].insert(points[j]);
        }
        else {
          if (pts[ln].find(points[j]) == pts[ln].end()) {
            mp[ln] += cnt[points[j]];
            pts[ln].insert(points[j]);
          }
          if (pts[ln].find(points[i]) == pts[ln].end()) {
            mp[ln] += cnt[points[i]];
            pts[ln].insert(points[i]);
          }
        }
        if (mp[ln] > mx) mx = mp[ln];
      }
    }
    if (mx == -1) return mxd;
    return max(mx, mxd);
  }
};