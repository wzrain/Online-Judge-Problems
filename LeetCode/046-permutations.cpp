// DFS
class Solution_0 {
public:
  vector<vector<int>> permute(vector<int>& nums) {
    if (nums.size() == 0) return {};
    if (nums.size() == 1) return {nums};
    vector<vector<int>> res;
    for (int i = 0; i < nums.size(); ++i) {
      swap(nums[i], nums.front());
      vector<int> remain(nums.begin() + 1, nums.end());
      vector<vector<int>> tmp = permute(remain);
      for (int j = 0; j < tmp.size(); ++j) {
        tmp[j].push_back(nums.front());
        res.push_back(tmp[j]);
      }
    }
    return res;
  }
};

// backtrack
// The previous solution needs no backtracking
// because every recursion step a copy of the original vector
// is created, so the original vector will not be modified.
// If we create a copy "tmp" for every step as is shown 
// in the comment below, there's no need of backtracing as well.
class Solution_1 {
public:
  void per(vector<int>& nums, int idx, vector<vector<int>>& res) {
    if (idx == nums.size()) {
      res.push_back(nums);
      return;
    }
    for (int i = idx; i < nums.size(); ++i) {
      swap(nums[i], nums[idx]);
      //vector<int> tmp(nums.begin(), nums.end());
      per(nums, idx + 1, res);
      swap(nums[i],nums[idx]);
    }
  }
  vector<vector<int>> permute(vector<int>& nums) {
    vector<vector<int>> res;
    per(nums, 0, res);
    return res;
  }
};