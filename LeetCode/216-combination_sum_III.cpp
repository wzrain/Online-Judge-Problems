class Solution {
public:
  void dfs(int k, int tgt, int idx, vector<int>& tmp, vector<vector<int>>& res) {
    if (k < 0) return;
    if (!tgt) {
      if (!k) res.push_back(tmp);
      return;
    }
    for (int i = idx; i <= 9; ++i) {
      if (tgt < i) continue;
      tmp.push_back(i);
      dfs(k - 1, tgt - i, i + 1, tmp, res);
      tmp.pop_back();
    }
  }
  vector<vector<int>> combinationSum3(int k, int n) {
    vector<vector<int>> res;
    vector<int> tmp;
    dfs(k, n, 1, tmp, res);
    return res;
  }
};