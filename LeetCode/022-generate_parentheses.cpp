// backtracking solution
class Solution_dfs {
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

// BFS
class Solution_bfs {
public:
  struct node {
    string str;
    int step, num;
    node (string tmp, int s = 0, int n = 0) : str(tmp), step(s), num(n) {}
  };
  vector<string> generateParenthesis(int n) {
    vector<string> res;
    queue<node> q;
    q.push(node("", 0, 0));
    while (!q.empty()) {
      int s = q.front().step, i = q.front().num;
      if (s == 2 * n) {
        res.push_back(q.front().str);
        q.pop();
        continue;
      }
      if (i == 0) q.push(node(q.front().str + '(', s + 1, i + 1));
      else if (s + i == 2 * n) q.push(node(q.front().str + ')', s + 1, i - 1));
      else {
        q.push(node(q.front().str + '(', s + 1, i + 1));
        q.push(node(q.front().str + ')', s + 1, i - 1));
      }
      q.pop();
    }
    return res;
  }
};

// dp solution
// dp(n) = \Sigma_{i = 0}^{n - 1}'(' + dp[i] + ')' + dp[n - i - 1]
class Solution_dp {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    for (int i = 1; i <= n; ++i) {
      for (int j = 0; j < i; ++j) {
        for (string s1 : dp[j]) {
          for (string s2 : dp[i - j - 1]) {
            dp[i].push_back('(' + s1 + ')' + s2);
          }
        }
      }
    }
    return dp[n];
  }
};

// another dp solution
// from the equivalent graph
class Solution_dp2 {
public:
  vector<string> generateParenthesis(int n) {
    vector<vector<string>> dp(n + 1);
    dp[0] = {""};
    for (int i = 1; i <= n; ++i) {
      for (string str : dp[i - 1]) {
        dp[i].push_back(str + "()");
        int j = str.length() - 1;
        while (str[j] == ')') {
          dp[i].push_back(str.substr(0, j) + "()" + str.substr(j));
          j--;
        }
      }
    }
    return dp[n];
  }
};