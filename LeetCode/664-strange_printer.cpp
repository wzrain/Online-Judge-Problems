class Solution {
public:
    int dfs(string& s, int i, int j, int ch, vector<vector<vector<int>>>& dp) {        
        if (i > j) return 0;
        if (dp[i][j][ch] != -1) return dp[i][j][ch];
        int res = 1 + dfs(s, i + 1, j, s[i] - 'a', dp);
        for (int k = i; k <= j; ++k) {
            if (s[k] == ch + 'a') {
                int l = dfs(s, i, k - 1, ch, dp);
                if (l >= res) continue;
                res = min(res, l + dfs(s, k + 1, j, ch, dp));
            }
        }
        dp[i][j][ch] = res;
        return res;
    }
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int len = s.length();
        // Here we could replace the continuous same letters with one letter, 
        // e.g. replace "aaa" with "a", since the result won't be different.

        // dp[i][j][ch] indicates the min print number for interval [i, j] 
        // and the previous print is character ch.
        vector<vector<vector<int>>> dp(len, vector<vector<int>>(len, vector<int>(26, -1)));
        return 1 + dfs(s, 0, len - 1, s[0] -'a', dp);
    }
};