#include <iostream>
#include <stdio.h>
#include <limits.h>

using namespace std;

int vnum, pnum;
int v[305];
int dp[305][305];
int sum[305][305];

void init() {
    scanf("%d%d", &vnum, &pnum);
    for (int i = 0; i < vnum; ++i) {
        scanf("%d", &v[i]);
    }
    for (int i = 0; i <= vnum; ++i) {
        for (int j = 0; j <= pnum; ++j) {
            dp[i][j] = -1;
        }
    }
    for (int i = 0; i < vnum; ++i) {
        for (int j = 0; j < i; ++j) {
            for (int k = j + 1; k < i; ++k) {
                sum[j][i] += min(v[k] - v[j], v[i] - v[k]);
            }
        }
    }
}

int dfs(int idx, int tgt) {
    if (dp[idx][tgt] != -1) return dp[idx][tgt];
    if (tgt == 1) {
        int res = 0;
        for (int j = idx + 1; j < vnum; ++j) {
            res += v[j] - v[idx];
        }
        dp[idx][tgt] = res;
        return res;
    }
    int res = INT_MAX;
    for (int i = idx + 1; i <= vnum - (tgt - 1); ++i) {
        // int tmp = dfs(i, tgt - 1);
        // for (int j = idx + 1; j <= i - 1; ++j) {
        //     tmp += min(v[j] - v[idx], v[i] - v[j]);
        // }
        res = min(res, dfs(i, tgt - 1) + sum[idx][i]);
    }
    dp[idx][tgt] = res;
    return res;
}

void solve() {
    int res = INT_MAX;
    int gap = 0;
    for (int i = 0; i <= vnum - pnum; ++i) {
        int tmp = dfs(i, pnum);
        // for (int j = 0; j < i; ++j) {
        //     tmp += (v[i] - v[j]);
        // }
        if (i > 0) {
            gap += (v[i] - v[i - 1]) * i;
        }
        tmp += gap;
        res = min(res, tmp);
    }
    printf("%d\n", res);
}

void solve2() {
    int gap = 0;
    for (int i = vnum - 1; i >= 0; --i) {
        dp[i][1] = 0;
        if (i < vnum - 1) {
            gap += (v[i + 1] - v[i]) * (vnum - i - 1);
        }
        dp[i][1] += gap;
    }
    for (int j = 2; j <= pnum; ++j) {
        for (int i = 0; i <= vnum - j; ++i) {
            dp[i][j] = INT_MAX;
            for (int k = i + 1; k <= vnum - j + 1; ++k) {
                // int tmp = dp[k][j - 1];
                // for (int mid = i + 1; mid < k; ++mid) {
                //     tmp += min(v[mid] - v[i], v[k] - v[mid]);
                // }
                dp[i][j] = min(dp[i][j], dp[k][j - 1] + sum[i][k]);
            }
        }
    }
    int res = INT_MAX;
    gap = 0;
    for (int i = 0; i <= vnum - pnum; ++i) {
        if (i > 0) {
            gap += (v[i] - v[i - 1]) * i;
        }
        dp[i][pnum] += gap;
        res = min(dp[i][pnum], res);
    }
    printf("%d\n", res);
}

int main() {
    init();
    solve();
    return 0;
}