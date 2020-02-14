class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        vector<pair<int, int>> env(n);
        for (int i = 0; i < n; ++i) {
            env[i] = make_pair(envelopes[i][0], envelopes[i][1]);
        }
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.first != p2.first) return p1.first < p2.first;
            return p1.second > p2.second;
        };
        sort(env.begin(), env.end(), cmp);
        vector<pair<int, int>> dp(n);
        int len = 0;
        for (int i = 0; i < n; ++i) {
            int l = 0, r = len, tgt = env[i].second;
            while (l < r) {
                int mid = (l + r) / 2;
                if (dp[mid].second < tgt) l = mid + 1;
                else r = mid;
            }
            dp[l] = env[i];
            if (l == len) len++;
        }
        return len;
    }
};