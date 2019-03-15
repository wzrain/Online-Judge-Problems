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
    vector<int> sums(k, 0);
    return dfs(nums, 0, sums, k, target);
  }
};

// quicker backtrack solution(still wondering why)
// visited indicates the used numbers.
// still wondering why the pruning from 416 can't be used here.'
class Solution {
public:
  bool dfs(vector<int>& nums, int idx, int k, int target, int sum, vector<int>& visited) {
    if (k == 0) return true;
    if (sum == 0) return dfs(nums, 0, k - 1, target, target, visited);
    for (int i = idx; i < nums.size(); ++i) {
      if (visited[i]) continue;
      visited[i] = 1;
      if(sum >= nums[i] && dfs(nums, i + 1, k, target, sum - nums[i], visited)) 
        return true;
      visited[i] = 0;
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
    vector<int> visited(nums.size(), 0);
    return dfs(nums, 0, k, target, target, visited);
  }
};