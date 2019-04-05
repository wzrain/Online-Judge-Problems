// dfs solution with memoization and pruning
class Solution {
public:
  int dfs(vector<int>& nums, int idx, vector<int>& dp) {
    if (dp[idx] != -1) return dp[idx];
    if (idx == nums.size() - 1) return 0;
    int res = INT_MAX;
    for (int i = 1; i <= nums[idx]; ++i) {
      if (i + idx >= nums.size()) break;
      if (i + idx != nums.size() - 1 && nums[i + idx] < nums[i + idx - 1]) continue;
      if (i + idx != nums.size() - 1 && nums[i + idx] < nums[idx] - i) continue;
      int sp = dfs(nums, idx + i, dp);
      if (sp != -1) res = min(res, sp + 1);
    }
    if (res == INT_MAX) return -1;
    dp[idx] = res;
    return dp[idx];
  }
  int jump(vector<int>& nums) {
    vector<int> dp(nums.size(), -1);
    return dfs(nums, 0, dp);
  }
};