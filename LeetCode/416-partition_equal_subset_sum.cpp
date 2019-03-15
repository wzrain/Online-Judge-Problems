// actually there is f[j][i] indicating 
// whether the sum i can be summed from the first j numbers.
// and the first dimension concerning j could be reused
// so the space cost can be reduced.
class Solution_dp {
public:
  bool canPartition(vector<int>& nums) {
    if (nums.empty()) return true;
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum & 1) return false;
    int half = sum / 2;
    vector<int> f(half + 1, 0);
    f[0] = 1;
    for (int j = 0; j < nums.size(); ++j) {
      for (int i = half; i >= 0; --i) {
        if (nums[j] > half) return false;
        if(i >= nums[j] && f[i - nums[j]]) f[i] = 1;
      }
    }
    return f[half];
  }
};

// key pruning is to sort the vector reversely 
// so we can get a impossible number combination early
// so that more recursion branches are pruned.
class Solution_dfs {
public:
  bool dfs(vector<int>& nums, int i, int sum) {
    if (sum == 0) return true;
    if (i >= nums.size()) return false;
    // instead of sum < 0, which will bring extra for loops
    if (sum < nums[i]) return false;
    for (int j = i; j < nums.size(); ++j) {
      if(dfs(nums, j + 1, sum - nums[j])) return true;
    }
    return false;
  }
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum & 1) return false;
    int half = sum / 2;
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    return dfs(nums, 0, half);
  }
};