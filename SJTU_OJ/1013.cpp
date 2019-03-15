#include <iostream>
#include <stdio.h>

using namespace std;

int V, n, v[1005], w[10005];
int f[10005];

void init() {
  scanf("%d%d", &V, &n);
  for (int i = 1; i <= n; ++i) scanf("%d%d", &v[i], &w[i]);
}

void solve() {
  for (int j = 0; j <= V; ++j) {
    for (int i = 1; i <= n; ++i) {
      f[j] = f[j];
      if (j - v[i] >= 0 && f[j] < f[j - v[i]] + w[i]) {
        f[j] = f[j - v[i]] + w[i];
      }
    }
  }
  printf("%d", f[V]);
}

int main() {
  init();
  solve();
  return 0;
}
