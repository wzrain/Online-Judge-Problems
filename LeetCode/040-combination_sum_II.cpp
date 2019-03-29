class Solution {
public:
  void dfs(vector<int>& cd, int tgt, int idx, vector<int>& tmp, vector<vector<int>>& res) {
    if (!tgt) {
      res.push_back(tmp);
      return;
    }
    for (int i = idx; i < cd.size(); ++i) {
      // same idea from 90
      // duplicate if same numbers appear in the same loop
      if (tgt < cd[i] || (i > idx && cd[i] == cd[i - 1])) continue;
      tmp.push_back(cd[i]);
      dfs(cd, tgt - cd[i], i + 1, tmp, res);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    vector<vector<int>> res;
    vector<int> tmp;
    sort(candidates.begin(), candidates.end());
    dfs(candidates, target, 0, tmp, res);
    return res;
  }
};