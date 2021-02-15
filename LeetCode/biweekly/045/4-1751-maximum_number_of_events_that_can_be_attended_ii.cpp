// dp[j][i] stands for the maximum value with at most i events attended for the events starting from index j.
class Solution {
public:
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());
        vector<int> next(n, 0);
        for (int i = 0; i < n; ++i) {
            int fin = events[i][1];
            int l = i, r = n;
            while (l < r) {
                int mid = (l + r) / 2;
                if (events[mid][0] > fin) r = mid;
                else l = mid + 1;
            }
            next[i] = l;
        }
        // Space complexity can be optimized.
        // vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        vector<vector<int>> dp(n + 1, vector<int>(2, 0));
        for (int i = 1; i <= k; ++i) {
            for (int j = n - 1; j >= 0; --j) {
                // Here we do not need to consider dp[j][i - 1] because the dp[next[j]][i - 1] 
                // incurs the situation where the actual maximum value may not need i events. 
                // Because when this type of situation occurs, there will be certain events j 
                // having a large value with next[j] == n (otherwise we can fit more values in 
                // there), which is covered since dp[n][i] is always 0.
                // dp[j][i & 1] = max(dp[j][(i - 1) & 1], dp[j + 1][i & 1]);
                dp[j][i & 1] = max(dp[j + 1][i & 1], dp[next[j]][(i - 1) & 1] + events[j][2]);
            }
        }
        int res = 0;
        for (int j = 0; j < n; ++j) {
            res = max(res, dp[j][k & 1]);
        }
        return res;
    }
};