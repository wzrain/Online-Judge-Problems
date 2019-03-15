// backtrack solution
// to check the current number belong to which subset
// probably TLE if more large testcases are added
class Solution {
public:
  bool dfs(vector<int>& nums, int idx, vector<int> sums, int k, int target) {
    if (idx == nums.size()) return true;
    for (int i = 0; i < k; ++i) {
      if (nums[idx] + sums[i] <= target) {
        sums[i] += nums[idx];
        if (dfs(nums, idx + 1, sums, k, target)) return true;
        sums[i] -= nums[idx];
      }
    }
    return false;
  }
  bool canPartitionKSubsets(vector<int>& nums, int k) {
    if (nums.empty()) return true;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum % k) return false;
    int target = sum / k;
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    vector<int> sums(k, 0);
    return dfs(nums, 0, sums, k, target);
  }
};