// backtracking solution
class Solution {
public:
  void dfs(int n, int cnt, int i, vector<string>& res, string& tmp) {
    if (cnt == 2 * n) {
      res.push_back(tmp);
      return;
    }
    if (i == 0) {
      tmp.push_back('(');
      dfs(n, cnt + 1, 1, res, tmp);
      tmp.pop_back();
    }
    else if (cnt + i == 2 * n) {
      tmp.push_back(')');
      dfs(n, cnt + 1, i - 1, res, tmp);
      tmp.pop_back();
    }
    else {
      tmp.push_back('(');
      dfs(n, cnt + 1, i + 1, res, tmp);
      tmp.pop_back();
      tmp.push_back(')');
      dfs(n, cnt + 1, i - 1, res, tmp);
      tmp.pop_back();
    }
  }
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    string tmp = "";
    dfs(n, 0, 0, res, tmp);
    return res;
  }
};