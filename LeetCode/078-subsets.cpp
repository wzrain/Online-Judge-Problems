// recursive
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    if (nums.empty()) {
      res.push_back({});
      return res;
    }
    int tmp = nums.back();
    nums.pop_back();
    res = subsets(nums);
    int sz = res.size();
    for (int i = 0; i < sz; ++i) {
      vector<int> cp = res[i];
      cp.push_back(tmp);
      res.push_back(cp);
    } 
    return res;
  }
};

// non-recursive. Save the space without copying each subset when adding a new number.
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    res.push_back({});
    for (int i = 0; i < nums.size(); ++i) {
      int sz = res.size();
      for (int j = 0; j < sz; ++j) {
        //vector<int> cp = res[j];
        res.push_back(res[j]);
        res.back().push_back(nums[i]);
      }
    }
    return res;
  }
};

// backtracking
class Solution {
public:
  void dfs(vector<int>& nums, int i, vector<vector<int>>& res, vector<int> tmp) { 
    res.push_back(tmp);
    //if (i == nums.size()) return;
    for (int j = i; j < nums.size(); ++j) {
      tmp.push_back(nums[j]);
      dfs(nums, j + 1, res, tmp);
      tmp.pop_back();
    }
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(nums, 0, res, tmp);
    return res;
  }
};

// another recursive solution
class Solution {
public:
  void dfs(vector<int>& nums, int i, vector<int> tmp, vector<vector<int>>& res) {
    if (i == nums.size()) {
      res.push_back(tmp);
      return;
    }
    dfs(nums, i + 1, tmp, res);
    tmp.push_back(nums[i]);
    dfs(nums, i + 1, tmp, res);
  }
  vector<vector<int>> subsets(vector<int>& nums) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(nums, 0, tmp, res);
    return res;
  }
};

// bits manipulation
class Solution {
public:
  vector<vector<int>> subsets(vector<int>& nums) {
    int total = 1 << nums.size();
    vector<vector<int>> res(total);
    for (int i = 0; i < total; ++i) {
      for (int j = 0; j < nums.size(); ++j) {
        if ((i >> j) & 1) res[i].push_back(nums[j]);
      }
    }
    return res;
  }
};