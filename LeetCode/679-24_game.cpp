class Solution {
// recursively calculate different sums, and make elements unchanged
public:
  bool equal(double a, double b) { return abs(a - b) < 0.0000000001; }
  bool helper(vector<int>& nums, vector<int>& idx, double target) {
    int n = idx.size();
    if (n == 1) return target == nums[idx[0]];
    if (n == 2) {
      int mx = max(nums[idx[0]], nums[idx[1]]), mn = min(nums[idx[0]], nums[idx[1]]);
      target = abs(target);
      if (target < 1) target = 1.0 / target;
      // return target == mx + mn || target == mx - mn || target == mx * mn || target == mx * 1.0 / mn;
      return equal(target, mx + mn) || equal(target, mx - mn) ||
             equal(target, mx * mn) || equal(target, mx * 1.0 / mn);
    }
    for (int i = 0; i < n; ++i) {
      vector<int> new_idx;
      for (int j = 0; j < n; ++j) {
        if (j == i) continue;
        new_idx.push_back(idx[j]);
      }
      if (helper(nums, new_idx, target - nums[idx[i]])) return true;
      if (helper(nums, new_idx, target + nums[idx[i]])) return true;
      if (helper(nums, new_idx, target / nums[idx[i]])) return true;
      if (target && helper(nums, new_idx, nums[idx[i]] / target)) return true;
    }
    if (n == 4) {
      for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
          if (j == i) continue;
          vector<int> idx1 = {i, j};
          vector<int> idx2;
          for (int k = 0; k < 4; ++k) {
            if (k == i || k == j) continue;
            idx2.push_back(k);
          }
          if ((helper(nums, idx1, 2) && helper(nums, idx2, 12)) ||
              (helper(nums, idx1, 3) && helper(nums, idx2, 8))  ||
              (helper(nums, idx1, 4) && helper(nums, idx2, 6))  ||
              (helper(nums, idx1, 6) && helper(nums, idx2, 4))  ||
              (helper(nums, idx1, 8) && helper(nums, idx2, 3))  ||
              (helper(nums, idx1, 12) && helper(nums, idx2, 2))) return true;
        }
      }
    }
    return false;
  }
  bool judgePoint24(vector<int>& nums) {
    vector<int> idx = {
      0, 1, 2, 3
    };
    return helper(nums, idx, 24);
  }
};