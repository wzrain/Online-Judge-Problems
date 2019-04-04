// If we calculate the optimal value in a certain interval [i, j] as
// dp[i][j], for the entire problem, however, it might not be the best
// result, since the elements inside [i, j] might be combined with the
// same color outside [i, j] and create a larger point.
// So when we deal with an interval, we need to somehow add the "outside"
// information into the process. So we focus on the first element of this
// interval. Notice that the first interval is actually a general representation
// of this interval, because in further recursion(or dynamic programming) process,
// any elements in the current interval could be the "first" element in another 
// certain interval, so we don't need to overthink about these elements. Let the
// code do the work itself.
// In the current interval, there might be several blocks(adjacent elements with
// the same color have been grouped into one block and a turnings vector is calculated
// accordingly to record every group's starting index) that could be combined with
// the first block of the interval. But we don't need to enumerate each combination.
// Again let the code do the work(Actually there is a similar situation in the problem
// about regular expression matching). Just search the situation where the first block
// combines with each of them and the further recursion will combine more of them and 
// add up the combination.
// And for the "outside" information, we add another parameter to record how many elements
// the current first block has already combined from its left. So every time it combines
// a new block with the same color, this parameter will increase. Or the first block might
// combine no new blocks in this interval, then this paramater plus the block it itself
// is the final k to calculate its k * k point. At this point, the problem could be separated
// into subproblems that are consistent with itself.
class Solution {
public:
  int dfs(vector<int>& boxes, vector<int>& turnings, int i, int j, int left, vector<vector<vector<int>>>& dp) {
    if (dp[i][j][left]) return dp[i][j][left];
    int cur = turnings[i + 1] - turnings[i];
    if (i == j) return (left + cur) * (left + cur);
    int res = (left + cur) * (left + cur) + dfs(boxes, turnings, i + 1, j, 0, dp);
    for (int k = i + 1; k <= j; ++k) {
      if (boxes[turnings[i]] != boxes[turnings[k]]) continue;
      int tmp = dfs(boxes, turnings, i + 1, k - 1, 0, dp) + dfs(boxes, turnings, k, j, left + cur, dp);
      if (res < tmp) res = tmp;
    }
    dp[i][j][left] = res;
    return dp[i][j][left];
  }
  int removeBoxes(vector<int>& boxes) {
    if (boxes.empty()) return 0;
    vector<int> turnings;
    turnings.push_back(0);
    for (int i = 1; i < boxes.size(); ++i) {
      if (boxes[i - 1] != boxes[i]) turnings.push_back(i);
    }
    turnings.push_back(boxes.size());
    vector<vector<vector<int>>> dp(turnings.size(), vector<vector<int>>(turnings.size(), vector<int>(boxes.size(), 0)));
    return dfs(boxes, turnings, 0, turnings.size() - 2, 0, dp);
  }
};