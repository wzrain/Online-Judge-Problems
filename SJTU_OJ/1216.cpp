#include <iostream>
#include <stdio.h>

using namespace std;

int h[20005], hsize = 0;

void up(int i) {
  int x = h[i], pidx = i, idx = pidx >> 1;
  while(idx > 0 && x < h[idx]) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx >>= 1;
  }
}

void ins(int x) {
  h[++hsize] = x;
  up(hsize);
}

int fd(int x) {
  int m = 2000000000, idx = 1;
  for (int i = 1; i <= hsize; ++i) {
    if (h[i] > x && h[i] < m) {
      idx = i;
      m = h[i];
    }
  }
  return idx;
}

void dec(int i, int v) {
  h[i] -= v;
  up(i);
}

void solve() {
  int m;
  scanf("%d", &m);
  for (int iii = 0; iii < m; ++iii) {
    char s[10];
    scanf("%s", s);
    if (s[0] == 'i') {
      int x;
      scanf("%d", &x);
      ins(x);
    }
    else if (s[0] == 'f') {
      int x;
      scanf("%d", &x);
      printf("%d\n", fd(x));
    }
    else if (s[0] == 'd') {
      int i, v;
      scanf("%d%d", &i, &v);
      dec(i, v);
    }
  }
}

int main() {
  solve();
  return 0;
}
