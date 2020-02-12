#include <iostream>
#include <stdio.h>
#include <vector>
#include <limits.h>
#include <algorithm>

#define INF 1e9

using namespace std;

int n, v, rx;
int x[1005], b[1005];
int dp[1005][1005][2], sum[1005];

bool init() {
    if (scanf("%d%d%d", &n, &v, &rx) == EOF) return false;
    for (int i = 0; i < n; ++i) {
        scanf("%d%d", &x[i], &b[i]);
    }
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= n; ++j) {
            dp[i][j][0] = dp[i][j][1] = -1;
        }
    }
    return true;
}

int dfs(vector<pair<int, int>>& nx, int i, int j, int dir, int src) {
    if (i == j) {
        dp[i][j][0] = dp[i][j][1] = 0;
        return 0;
    }
    if (dp[i][j][dir] != -1) return dp[i][j][dir];
    int res = INF;
    if (dir == 0 && i < src) {
        int lf = dfs(nx, i + 1, j, 0, src);
        int tl = (nx[i + 1].first - nx[i].first);
        int rt = dfs(nx, i + 1, j, 1, src);
        int tr = (nx[j].first - nx[i].first);
        int rf = lf + tl * (sum[n + 1] - sum[j + 1] + sum[i + 1]);
        int rr = rt + tr * (sum[n + 1] - sum[j + 1] + sum[i + 1]);
        res = min(res, min(rf, rr));
    }
    if (dir == 1 && j > src) {
        int lf = dfs(nx, i, j - 1, 0, src);
        int tl = (nx[j].first - nx[i].first);
        int rt = dfs(nx, i, j - 1, 1, src);
        int tr = (nx[j].first - nx[j - 1].first);
        int rf = lf + tl * (sum[n + 1] - sum[j] + sum[i]);
        int rr = rt + tr * (sum[n + 1] - sum[j] + sum[i]);
        res = min(res, min(rf, rr));
    }
    dp[i][j][dir] = res;
    return res;
}

void solve() {
    vector<pair<int, int>> nx(n + 1);
    for (int i = 0; i < n; ++i) {
        nx[i].first = x[i];
        nx[i].second = b[i];
    }
    nx[n].first = rx;
    nx[n].second = 0;
    sort(nx.begin(), nx.end());
    int idx = 0;
    sum[0] = 0;
    for (int i = 0; i <= n; ++i) {
        if (nx[i].first == rx) {
            idx = i;
        }
        sum[i + 1] = nx[i].second + sum[i];
    }
    printf("%d\n", min(dfs(nx, 0, n, 0, idx), dfs(nx, 0, n, 1, idx)) * v);
}

void solve2() {
    vector<pair<int, int>> nx(n + 1);
    for (int i = 0; i < n; ++i) {
        nx[i].first = x[i];
        nx[i].second = b[i];
    }
    nx[n].first = rx;
    nx[n].second = 0;
    sort(nx.begin(), nx.end());
    int idx = 0;
    sum[0] = 0;
    for (int i = 0; i <= n; ++i) {
        if (nx[i].first == rx) {
            idx = i;
        }
        sum[i + 1] = nx[i].second + sum[i];
    }
    dp[idx][idx][0] = dp[idx][idx][1] = 0;
    for (int i = idx; i >= 0; --i) {
        for (int j = idx; j <= n; ++j) {
            if (i == j) continue;
            int lfa = dp[i + 1][j][0] + (sum[n + 1] - sum[j + 1] + sum[i + 1]) * (nx[i + 1].first - nx[i].first);
            int lfb = dp[i + 1][j][1] + (sum[n + 1] - sum[j + 1] + sum[i + 1]) * (nx[j].first - nx[i].first);
            dp[i][j][0] = min(dp[i][j][0], min(lfa, lfb));
            int rta = dp[i][j - 1][0] + (sum[n + 1] - sum[j] + sum[i]) * (nx[j].first - nx[i].first);
            int rtb = dp[i][j - 1][1] + (sum[n + 1] - sum[j] + sum[i]) * (nx[j].first - nx[j - 1].first);
            dp[i][j][1] = min(dp[i][j][1], min(rta, rtb));
        }
    }
    printf("%d\n", min(dp[0][n][0], dp[0][n][1]) * v);
}

int main() {
    while(init()) solve();
    return 0;
}