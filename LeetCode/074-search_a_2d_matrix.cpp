class Solution {
public:
  bool bisearch(vector<vector<int>>& matrix, int l, int r, int t, int c) {
    if (l == r) return t == matrix[l / c][l % c];
    int mid = (l + r) / 2, x = mid / c, y = mid % c;
    if (t <= matrix[x][y]) return bisearch(matrix, l, mid, t, c);
    else return bisearch(matrix, mid + 1, r, t, c);
  }
  bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty() || matrix[0].empty()) return false;
    int r = matrix.size(), c = matrix[0].size(), tsz = r * c;
    //return bisearch(matrix, 0, tsz - 1, target, c);
    int l = 0, h = tsz - 1;
    while (l < h) {
      int mid = (l + h) / 2, x = mid / c, y = mid % c;
      if (target <= matrix[x][y]) h = mid;
      else l = mid + 1;
    } 
    return matrix[l / c][l % c] == target;
  }
};