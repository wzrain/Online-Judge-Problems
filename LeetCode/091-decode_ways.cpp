// Top-down and bottom-up dp solutions.
// Note that '0' has to be combined with a previous non-
// zero digit. So scan the original string to find 
// unrepresentable '0's, and if a '0' can be combined 
// with a '1' or '2' in the previous spot, just delete
// both of them from the original string, and deal with
// the remaining string.
class Solution {
public:
    int dfs(string& s, int idx, vector<int>& dp) {
        if (idx >= s.length()) return 1;
        if (dp[idx] != -1) return dp[idx];
        int res = dfs(s, idx + 1, dp);
        if (idx < s.length() - 1 && (s[idx] == '1' || (s[idx] == '2' && s[idx + 1] >= '0' && s[idx + 1] <= '6'))) res += dfs(s, idx + 2, dp);
        dp[idx] = res;
        return res;
    }
    int numDecodings(string s) {
        string now;
        int len = s.length();
        for (int i = 0; i < len; ++i) {
            if (s[i] == '0') {
                if (i == 0 || (s[i - 1] != '1' && s[i - 1] != '2')) return 0;
                else if (!now.empty()) now.pop_back();
                continue;
            }
            now += s[i];
        }
        // vector<int> dp(now.length(), -1);
        int nl = now.length();
        vector<int> dp(nl + 1, 0);
        dp[0] = 1;
        for (int i = 0; i < nl; ++i) {
            dp[i + 1] = dp[i];
            if (i > 0 && (now[i - 1] == '1' || (now[i - 1] == '2' && now[i] >= '0' && now[i] <= '6'))) dp[i + 1] += dp[i - 1];
        }
        // return dfs(now, 0, dp);
        return dp[nl];
    }
};