#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

int n, m, A[105], C[105];
int dp[100005], cnt[100005];

void solve() {
  while (1) {
    scanf("%d%d", &n, &m);
    if (!n && !m) return;
    for (int i = 1; i <= n; ++i) scanf("%d", &A[i]);
    for (int i = 1; i <= n; ++i) scanf("%d", &C[i]);
    memset(dp, 0, sizeof(dp));
    dp[0] = 1;
    for (int i = 1; i <= n; ++i) {
      memset(cnt, 0, sizeof(cnt));
      for (int v = 1; v <= m; ++v) {
        if (dp[v]) continue;
        if (dp[v - A[i]] && cnt[v - A[i]] < C[i]) {
          dp[v] = 1;
          cnt[v] = cnt[v - A[i]] + 1;
        }
      }
    }
    int sum = 0;
    for (int v = 1; v <= m; ++v) sum += dp[v];
    printf("%d\n", sum);
  }
}

int main() {
  solve();
  return 0;
}
