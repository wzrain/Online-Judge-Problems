// dp[i] means the min cut of subarray [0, i]. Whether an interval is palindrome can also be calculated in a dp way. 
// The reason why two-dimension dp is unnecessary is that this dp process is actually associative. If we 
// calculate dp[i][l] = f(dp[i][j], dp[j][k], dp[k][l]), it will be the same if we calculate either f(dp[i][k], dp
// [k][l]) or f(dp[i][j], dp[j][l]). Therefore we can directly compute what is an equivalent of dp[0][i]. In 
// problems like 312-burst_balloons or SJTU-OJ-1077, the dp state transfer function is not associative, so we 
// need to examine every sub-intervals and their combination to get the maximum way of combining the intervals.
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        vector<vector<int>> palindrome(len, vector<int>(len, 0));
        vector<int> dp(len, 0);
        for (int i = 0; i < len; ++i) {
            int res = i;
            for (int j = 0; j <= i; ++j) {
                if (s[i] == s[j] && (j >= i - 1 || palindrome[j + 1][i - 1])) {
                    palindrome[j][i] = 1;
                    res = min(res, j == 0 ? 0 : (1 + dp[j - 1]));
                }
            }
            dp[i] = res;
        }
        return dp[len - 1];
    }
};