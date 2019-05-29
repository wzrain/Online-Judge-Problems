// dp with memoization
// focus on the first split position and let the code do the work
class Solution {
public:
  long dfs(int n, int m, int idx, vector<vector<long>>& dp) {
    if (m > n - idx) return LONG_MAX;
    if (dp[idx][m] != LONG_MAX) return dp[idx][m];
    for (int i = idx; i < n; ++i) {
      long si = dp[idx][1] - (i == n - 1 ? 0 : dp[i + 1][1]); // sum from idx to i
      if (si > dp[idx][m]) break; // Pruning: the final result (dp[idx][m]) would be no larger than si. (Only non-negative)
      long tmp = dfs(n, m - 1, i + 1, dp);
      dp[idx][m] = min(dp[idx][m], max(si, tmp));
    }
    return dp[idx][m];
  }
  int splitArray(vector<int>& nums, int m) {
    int n = nums.size();
    vector<vector<long>> dp(n, vector<long>(m + 1, LONG_MAX));
    dp[n - 1][1] = nums[n - 1];
    for (int i = n - 2; i >= 0; --i) {
      dp[i][1] = dp[i + 1][1] + nums[i];
    }
    return dfs(n, m, 0, dp);
  }
};

// binary search solution
// The key of binary searching the answer is that the candidate answer set is limited.
// And here it's looking for the minimum of the maximum. So if there is a smaller value
// than mid that could be answet then all values larger than mid are eliminated.
// To identify the situation for eliminating all values no larger than mid, we need to
// prove that the answer must be larger than mid.
// Use the greedy strategy to make every segment as close to mid as possible. If the number
// of segments is larger than m, the final answer must be larger than mid because we have
// to combine some segments to reduce the number of segments to mid, which will increase
// some segments' sum larger than mid. Otherwise some value no larger than mid could be the
// answer so the right side of mid is eliminated. The greedy strategy is based on the condition
// that all numbers are non-negative.
// When searching for the minimum of the maximum, the "maximum" is to let mid as a cap
// and the "minimum" is to judge which side of mid is eliminated.
class Solution {
public:
  bool valid(vector<int>& nums, long mid, int m) {
    long tmp = 0, cnt = 1;
    for (auto n : nums) {
      tmp += n;
      if (tmp > mid) {
        tmp = n;
        cnt++;
        if (cnt > m) return true;
      }
    }
    return false;
  }
  int splitArray(vector<int>& nums, int m) {
    int mx = 0;
    long sum = 0;
    for (auto n : nums) {
      mx = max(mx, n);
      sum += n;
    }
    long l = mx, r = sum;
    while (l < r) {
      long mid = (l + r) / 2;
      if (valid(nums, mid, m)) l = mid + 1;
      else r = mid;
    }
    return l;
  }
};