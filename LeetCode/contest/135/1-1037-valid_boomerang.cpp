// Judge whether two slopes are the same. Judging whether the third point
// is in the line of the first two points might lead to float calculation.
class Solution {
public:
  bool isBoomerang(vector<vector<int>>& points) {
    return (points[1][1] - points[0][1]) * (points[2][0] - points[1][0]) != 
           (points[2][1] - points[1][1]) * (points[1][0] - points[0][0]);
  }
};

// 2S = x1 * (y2 - y3) + x2 * (y3 - y1) + x3 * (y1 - y2)
class Solution {
public:
  bool isBoomerang(vector<vector<int>>& points) {
    return points[0][0] * (points[1][1] - points[2][1]) + 
           points[1][0] * (points[2][1] - points[0][1]) + 
           points[2][0] * (points[0][1] - points[1][1]);
  }
};