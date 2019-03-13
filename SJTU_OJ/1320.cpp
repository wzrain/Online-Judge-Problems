#include <iostream>
#include <stdio.h>

using namespace std;

int n, tree[1005][1005], sum[1005][1005];

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= i; ++j) {
      scanf("%d", &tree[i][j]);
    }
  }
}

int Max(int a, int b) {
  return (a > b) ? a : b;
}

void solve() {
  for (int d = n; d >= 1; --d) {
    for (int i = 1; i <= d; ++i) {
      sum[d][i] = tree[d][i] + Max(sum[d + 1][i], sum[d + 1][i + 1]);
    }
  }
  printf("%d", sum[1][1]);
}

int main() {
  init();
  solve();
  return 0;
}
