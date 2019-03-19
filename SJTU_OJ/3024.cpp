#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, p, w, val;
int wm[10005], vs[10005], cnt = 0, f[1005];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &p, &w, &val);
    int tmp = 1;
    while (tmp < p) {
      wm[++cnt] = tmp * w;
      vs[cnt] = tmp * val;
      p -= tmp;
      tmp *= 2;
    }
    wm[++cnt] = p * w;
    vs[cnt] = p * val;
  }
}

void solve() {
  for (int i = 1; i <= cnt; ++i) {
    for (int v = m; v >= 0; --v) {
      if (v >= wm[i] && f[v - wm[i]] + vs[i] > f[v]) {
        f[v] = f[v - wm[i]] + vs[i];
      }
    }
  }
  printf("%d", f[m]);
}

int main() {
  init();
  solve();
  return 0;
}
