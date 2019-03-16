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
    // This version of pruning is exactly the same way of the dfs2 solution.
    // If the current nums[i] can't satisfy the sum, 
    // it doesn't bother to search for the situation where the nums[i] is unselected:
    // since the vector is sorted reversely, for this solution, 
    // it just erase the loop of i + 1 -> nums.size() - 1, 
    // and in the dfs2 it doesn't execute dfs(nums, sum, idx + 1).
    // So the previous selected number will be discarded (here the loop goes forward by 1,
    // and the previous selected number is exactly the previous number.
    // In the dfs2 it go back to the previous selected number 
    // and enter the recursion make that number deselected.
    // Since the vector is sorted reversely, we can prove that it is exactly the previous number.
    // Otherwise let the previous selected number is aj, and current nums[i] is ai, where i - j > 1,
    // so we have j < k < i such that aj + ak > sum so aj should already been discarded
    // when ak is visited. Therefore this two solution is actually equal.) 
    // So now nums[i] will be the current selected number,
    // and the recursion continues to check later numbers, which would've been checked
    // in the recursion where the terminal condition is sum < 0, in which case the nums[i] will be temporarily
    // discarded and the previous selected number will remain.
    // So what basically happens is we use nums[i + 1] to replace the previous selected number, 
    // which also reduce the temporary sum.
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

class Solution_dfs2 {
public:
  bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int i = 0; i < nums.size(); ++i) sum += nums[i];
    if (sum & 1) return false;
    sum /= 2;
    sort(nums.begin(), nums.end());
    reverse(nums.begin(), nums.end());
    return dfs(nums, sum, 0);
  }
  bool dfs(vector<int>& nums, int sum, int idx) {
    if (sum == 0) return true;
    if (idx >= nums.size()) return false;
    if (sum < nums[idx]) return false;
    
    return dfs(nums, sum - nums[idx], idx + 1) || dfs(nums, sum, idx + 1);
  }
};