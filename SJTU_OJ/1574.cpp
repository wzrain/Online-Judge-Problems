#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, k, x;

void init() {
  scanf("%d%d%d%d", &n, &m, &k, &x);
}

int quickPow(int p) {
  if (p == 0) return 1;
  if (p & 1) return (10 * quickPow(p - 1)) % n;
  return (quickPow(p >> 1) * quickPow(p >> 1)) % n;
}

int quickPowNonRecur(int p) {
  int res = 1, tmp = 10;
  while (p > 0) {
    if (p & 1) res = (res * tmp) % n;
    tmp = (tmp * tmp) % n;
    p >>= 1;
  }
  return res;
}

void solve() {
  printf("%d", (m * quickPowNonRecur(k) + x) % n);
}

int main() {
  init();
  solve();
  return 0;
}
