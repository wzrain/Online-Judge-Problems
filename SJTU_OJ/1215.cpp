#include <iostream>
#include <stdio.h>

using namespace std;

int h[20005], hsize = 0;

void ins(int x) {
  h[++hsize] = x;
  int pidx = hsize, idx = hsize >> 1;
  while (idx > 0 && x < h[idx]) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx >>= 1;
  }
}

void del() {
  h[1] = h[hsize--];
  int x = h[1], pidx = 1, idx = h[2] > h[3] ? 3 : 2;
  while (idx <= hsize && x > h[idx]) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx = h[idx * 2] > h[idx * 2 + 1] ? idx * 2 + 1 : idx * 2;
  }
}

void solve() {
  int m;
  scanf("%d", &m);
  char s[10];
  for (int xxx = 0; xxx < m; ++xxx) {
    scanf("%s", s);
    if (s[0] == 'i') {
      int v;
      scanf("%d", &v);
      ins(v);
    }
    else if (s[0] == 'd') del();
    else if (s[0] == 'm') printf("%d\n", h[1]);
  }
}

int main() {
  solve();
  return 0;
}
