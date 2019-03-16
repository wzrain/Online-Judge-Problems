#include <iostream>
#include <stdio.h>

using namespace std;

int n, t, x[100005], y[100005];

void init() {
  scanf("%d%d", &n, &t);
  for (int i = 0; i < n; ++i) scanf("%d", &x[i]);
  for (int i = 0; i < t; ++i) scanf("%d", &y[i]);
}

int bisearch(int l, int r, int g) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (g < x[mid]) return bisearch(l, mid, g);
  else return bisearch(mid + 1, r, g);
}

void solve() {
  for (int i = 0; i < t; ++i) {
    if (y[i] >= x[n - 1]) printf("%d\n", 0);
    else {
      int idx = bisearch(0, n - 1, y[i]);
      printf("%d\n", n - idx);
    }
  }
}

int main() {
  init();
  solve();
  return 0;
}
