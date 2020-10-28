class Solution {
public:
    int totalNQueens(int n) {
        vector<int> col(n, 0), slash(2 * n - 1, 0), backslash(2 * n - 1, 0);
        int res = 0;
        dfs(col, slash, backslash, 0, n, res);
        return res;
    }
    void dfs(vector<int>& col, vector<int>& slash, vector<int>& backslash, int i, int n, int& cnt) {
        if (i == n) {
            cnt++;
            return;
        }
        for (int j = 0; j < n; ++j) {
            if (!col[j] && !slash[i + j] && !backslash[n - 1 + i - j]) {
                col[j] = slash[i + j] = backslash[n - 1 + i - j] = 1;
                dfs(col, slash, backslash, i + 1, n, cnt);
                col[j] = slash[i + j] = backslash[n - 1 + i - j] = 0;
            }
        }
    }
};