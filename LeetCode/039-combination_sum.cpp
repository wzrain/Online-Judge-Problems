class Solution {
public:
  void dfs(vector<int>& candidates, int target, int idx, vector<int>& tmp, vector<vector<int>>& res) {
    if (!target) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx; i < candidates.size(); ++i) {
      if (target < candidates[i]) continue;
      tmp.push_back(candidates[i]);
      dfs(candidates, target - candidates[i], i, tmp, res);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    if (candidates.empty()) return res;
    vector<int> tmp;
    dfs(candidates, target, 0, tmp, res);
    return res;
  }
};

// This is also the same solution pattern in 416 if there's no pruning. 
// In 416, the pruning works because of the special target which is half the sum,
// and the mighty power of the pruning at 416 is mostly shown when the first element 
// is larger than half the sum, and the possible testcases ensured that
// the program will end quickly because most of the time the answer is true,
// and if it is true then the first element must be included.
// Here all the possible combinations towards a non-special target is required,
// so no prunings.