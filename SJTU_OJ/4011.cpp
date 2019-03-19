#include <iostream>
#include <stdio.h>

using namespace std;

int k, h;
int f[55][2][505];

void init() {
  scanf("%d%d", &k, &h);
  for (int j = 0; j < k; ++j) f[j][0][0] = f[j][0][1] = 1;
}

void bigAdd(int rj, int ri, int j1, int i1, int j2, int i2) {
  int l1 = f[j1][i1][0], l2 = f[j2][i2][0];
  int addtmp = 0, l = l1 > l2 ? l1 : l2;
  for (int i = 1; i <= l; ++i) {
    f[rj][ri][i] = f[j1][i1][i] + f[j2][i2][i] + addtmp;
    if (f[rj][ri][i] >= 10) {
      f[rj][ri][i] -= 10;
      addtmp = 1;
    }
    else addtmp = 0;
  }
  if (addtmp) f[rj][ri][++l] = 1;
  f[rj][ri][0] = l;
}

void bigPrint(int j, int i) {
  int l = f[j][i][0];
  for (int idx = l; idx >= 1; --idx) printf("%d", f[j][i][idx]);
}

void solve() {
  for (int i = 3; i <= h; ++i) {
    for (int j = k - 1; j >= 0; --j) {
      bigAdd(j, i % 2, j + 1, i % 2, k - 1 - j, (i + 1) % 2);
    }
  }
  for (int j = 0; j < k; ++j) bigAdd(k, (h + 1) % 2, k, (h + 1) % 2, j, h % 2);
  bigPrint(k, (h + 1) % 2);
}

int main(){
  init();
  solve();
  return 0;
}
