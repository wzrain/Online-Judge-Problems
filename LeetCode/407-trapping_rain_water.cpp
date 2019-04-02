// Boundary matters. According to the Cask Effect, the lowest position
// on the boundary is the determinant. In 1-D situation, the two pointers
// indicate the boundary. It went through all the heights that is inside
// the "cast"(lower than both the current cast boundary) and when two 
// boundary heights are both higher than the current cast boundary, there
// could be a new "cast" for more water.
// In 2-D situation, the boundary is a set of heights. Similar to 1-D situation,
// we search outside-in to find low heights inside the cast(here it's more like
// a pond) and higher cast for more water.
// In 1-D situation the "lowest" is easy to find(the lower height of the two pointers),
// in 2-D situation, a priority queue is used to record the current searching
// position, just like the two pointers in 1-D situation.
class Solution {
public:
  struct pos {
    int x, y, ht;
    pos(int xx = 0, int yy = 0, int h = 0) : x(xx), y(yy), ht(h) {}
  };
  int trapRainWater(vector<vector<int>>& heightMap) {
    if (heightMap.empty()) return 0;
    int r = heightMap.size(), c = heightMap.front().size();
    vector<vector<int>> visited(r, vector<int>(c, 0));
    int dir[5] = {-1, 0, 1, 0, -1}, res = 0;
    auto cmp = [](pos p1, pos p2) {
      return p1.ht >= p2.ht;
    };
    priority_queue<pos, vector<pos>, decltype(cmp)> pq(cmp);
    for (int i = 0; i < r; ++i) {
      if (!visited[i][0]) {
        pq.push(pos(i, 0, heightMap[i][0]));
        visited[i][0] = 1;
      }
      if (!visited[i][c - 1]) {
        pq.push(pos(i, c - 1, heightMap[i][c - 1]));
        visited[i][c - 1] = 1;
      }
    }
    for (int j = 0; j < c; ++j) {
      if (!visited[0][j]) {
        pq.push(pos(0, j, heightMap[0][j]));
        visited[0][j] = 1;
      }
      if (!visited[r - 1][j]) {
        pq.push(pos(r - 1, j, heightMap[r - 1][j]));
        visited[r - 1][j] = 1;
      }
    }
    int maxh = INT_MIN;
    while (!pq.empty()) { // contains the current searching position
                          // similar role as the two pointers in the 1-D situation
      int x = pq.top().x, y = pq.top().y, h = pq.top().ht;
      pq.pop();
      if (maxh < h) maxh = h;
      for (int d = 0; d < 4; ++d) {
        int nx = x + dir[d], ny = y + dir[d + 1];
        if (nx < 0 || nx >= r || ny < 0 || ny >= c || visited[nx][ny]) continue;
        if (heightMap[nx][ny] < maxh) res += (maxh - heightMap[nx][ny]);
        pq.push(pos(nx, ny, heightMap[nx][ny]));
        visited[nx][ny] = 1;
      }
    } 
    return res;
  }
};