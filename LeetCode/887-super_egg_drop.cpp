// O(knlogn) dp
// Use binary search to find the optimal intermediate position
// for each i-floor-j-egg situation.
class Solution {
public:
    int superEggDrop(int K, int N) {
        vector<vector<int>> dp(N + 5, vector<int>(K + 5, 0));
        for (int i = 1; i <= N; ++i) {
            dp[i][1] = i;
            for (int j = 2; j <= K; ++j) {
                int l = 1, r = i;
                while (l < r) {
                    int mid = (l + r) / 2;
                    if (dp[mid - 1][j - 1] >= dp[i - mid][j]) r = mid;
                    else l = mid + 1;
                }
                dp[i][j] = 1 + max(dp[l - 1][j - 1], dp[i - l][j]);
            }
        }
        return dp[N][K];
    }
};