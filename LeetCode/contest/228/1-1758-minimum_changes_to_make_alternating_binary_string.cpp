// dp solution
// This dp actually incurs that dp0 is the situation where the string starts with 10..., and dp1 corresponds 
// to the string starts with 01..., which means we just calculate the two situations and compare them.
// Another observation would be that dp0 + dp1 = len, since we need to flip len times to get 0101... to 1010..., 
// but we only need dp0 times if there are already dp1 done. Therefore we can just calculate the result res for 
// any of the two situations and compare res with n - res.
class Solution {
public:
    int minOperations(string s) {
        int len = s.length();
        // vector<vector<int>> dp(len + 1, vector<int>(2, 0));
        int dp1 = 0, dp0 = 0;
        for (int i = 0; i < len; ++i) {
            // if (s[i] == '1') {
            //     // dp[i + 1][1] = dp[i][0];
            //     // dp[i + 1][0] = dp[i][1] + 1;
            //     int tmp = 
            // }
            // else {
            //     dp[i + 1][1] = dp[i][0] + 1;
            //     dp[i + 1][0] = dp[i][1];
            // }
            int n1 = dp0 + (s[i] == '0'), n0 = dp1 + (s[i] == '1');
            dp0 = n0;
            dp1 = n1;
        }
        // return min(dp[len][0], dp[len][1]);
        return min(dp0, dp1);
    }
};