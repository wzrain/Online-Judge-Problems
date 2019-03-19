#include <iostream>
#include <stdio.h>

using namespace std;

int n, k, b[50];

void init() {
  scanf("%d%d", &n, &k);
}

void solve() {
  int tmp = n, cnt = 0, i = 0, add = 0;
  if (n <= k) {
    printf("%d", k - n);
    return;
  }
  while (tmp > 0) {
    if (tmp & 1) {
      cnt++;
      b[i++] = 1;
    }
    else b[i++] = 0;
    tmp >>= 1;
  }
  i = 0;
  while (cnt > k) {
    if (b[i]) {
      add += (1 << i);
      while (b[i]) {
        b[i] = 0;
        cnt--;
        i++;
      }
      b[i] = 1;
      cnt++;
    }
    else i++;
  }
  printf("%d", add);
}

int main() {
  init();
  solve();
  return 0;
}
