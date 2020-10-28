class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<int> col(n, 0), slash(2 * n - 1, 0), backslash(2 * n - 1, 0), idx;
        vector<vector<string>> res;
        dfs(res, col, slash, backslash, idx, 0, n);
        return res;
    }
    void dfs(vector<vector<string>>& res, vector<int>& col, vector<int>& slash, vector<int>& backslash, vector<int>& idx, int i, int n) {
        if (idx.size() == n) {
            vector<string> cur(n, string(n, '.'));
            for (int i = 0; i < n; ++i) {
                cur[i][idx[i]] = 'Q';
            }
            res.push_back(cur);
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!col[j] && !slash[i + j] && !backslash[n - 1 + i - j]) {
                col[j] = slash[i + j] = backslash[n - 1 + i - j] = 1;
                idx.push_back(j);
                dfs(res, col, slash, backslash, idx, i + 1, n);
                idx.pop_back();
                col[j] = slash[i + j] = backslash[n - 1 + i - j] = 0;
            }
        }
    }
};