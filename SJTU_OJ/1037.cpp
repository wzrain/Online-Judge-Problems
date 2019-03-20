#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, m, high[10005], low[10005];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) scanf("%d", &high[i]);
  for (int i = 0; i < m; ++i) scanf("%d", &low[i]);
  sort(high, high + n);
  sort(low, low + m);
}

void solve() {
  int lidx = m - 1, cnt = 0;;
  for (int i = n - 1; i >= 0; --i) {
    cnt++;
    while (lidx >= 0 && low[lidx] >= high[i]) lidx--;
    if (lidx >= 0) {
      cnt++;
      lidx--;
    }
  }
  printf("%d", cnt);
}

int main() {
  init();
  solve();
  return 0;
}
