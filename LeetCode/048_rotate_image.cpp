// directly rotate
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    int n = matrix.size();
    for (int i = 0; i < n / 2; ++i) {
      for (int j = i + 1; j < n - i; ++j) {
        int tmp = matrix[i][j];
        int ni = n - j - 1, nj = i, pi = i, pj = j;
        for (int x = 0; x < 3; ++x) {
          matrix[pi][pj] = matrix[ni][nj];
          pi = ni;
          pj = nj;
          nj = ni;
          if (x == 0) ni = n - i - 1;
          else if (x == 1) ni = j;
          else ni = i;
        }
        matrix[pi][pj] = tmp;
      }
    }
  }
};

// equals to first transpose the matrix and reverse it horizontally
// equals to first reverse it vertically and then transpose the matrix
class Solution {
public:
  void rotate(vector<vector<int>>& matrix) {
    if (matrix.empty()) return;
    reverse(matrix.begin(), matrix.end());
    for (int i = 0; i < matrix.size(); ++i) {
      for (int j = 0; j < i; ++j) {
        swap(matrix[i][j], matrix[j][i]);
      }
    }
  }
};