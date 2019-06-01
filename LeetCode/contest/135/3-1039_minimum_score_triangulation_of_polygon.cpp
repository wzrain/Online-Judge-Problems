// similar to 312-burst_balloons and SJTU_OJ-1073
// dp[i][j] indicates the minimum score of the polygon formed by vertex i to j.
// The "bursting" process in 312 is exactly the process of forming "triangles".
// The burst balloon is that one vertex of the triangle that is "isolated" by 
// the edge formed by the other two vertices and will not be connected to any
// other vertices of the original polygon.
// No need to consider in the circular way like SJTU_OJ-1073 because in 1073
// there is one extra process to combine the last two vertices into one, so the
// w could add up to n rather than n - 1 to find out the best "final remaining"
// vertex. Here we just need to find triangular combinations which is rotationally
// symmetric. So no need to use a 2 * n array.
class Solution {
public:
  int minScoreTriangulation(vector<int>& A) {
    int n = A.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for (int w = 2; w < n; ++w) {
      for (int i = 0; i < n - w; ++i) {
        dp[i][i + w] = INT_MAX;
        for (int j = i + 1; j < i + w; ++j) {
          int tmp = dp[i][j] + dp[j][i + w] + A[i] * A[j] * A[i + w];
          if (tmp < dp[i][i + w]) dp[i][i + w] = tmp;
        }
      }
    }
    return dp[0][n - 1];
  }
};