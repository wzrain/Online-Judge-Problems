#include <iostream>
#include <stdio.h>

using namespace std;

int n, solution[2][3][10005];

void init() {
  scanf("%d", &n);
}

void bigAdd(int ir, int jr, int i1, int j1, int i2, int j2) {
  int len1 = solution[i1][j1][0], len2 = solution[i2][j2][0];
  int addtmp = 0, i, len = (len1 < len2) ? len1 : len2;
  for (i = 1; i <= len; ++i) {
    solution[ir][jr][i] = solution[i1][j1][i] + solution[i2][j2][i] + addtmp;
    if (solution[ir][jr][i] >= 10) {
      solution[ir][jr][i] -= 10;
      addtmp = 1;
    }
    else addtmp = 0;
  }
  if (len1 < len2) {
    while (i <= len2) {
      solution[ir][jr][i] = solution[i2][j2][i] + addtmp;
      if (solution[ir][jr][i] >= 10) {
        solution[ir][jr][i] -= 10;
        addtmp = 1;
      }
      else addtmp = 0;
      i++;
    }
  }
  else if (len1 > len2){
    while (i <= len1) {
      solution[ir][jr][i] = solution[i1][j1][i] + addtmp;
      if (solution[ir][jr][i] >= 10) {
        solution[ir][jr][i] -= 10;
        addtmp = 1;
      }
      else addtmp = 0;
      i++;
    }
  }
  if (addtmp) solution[ir][jr][i++] = 1;
  solution[ir][jr][0] = i - 1;
}

void solve() {
  solution[0][1][0] = solution[0][1][1] = 1;
  solution[1][1][0] = solution[1][1][1] = 1;
  //solution[0][0][0] = solution[0][0][1] = 1;
  solution[0][2][0] = solution[1][2][0] = 1;
  solution[0][2][1] = solution[1][2][1] = 2;
  for (int i = 3; i <= n; ++i) {
    bigAdd(0, i % 3, 0, (i - 1) % 3, 1, (i - 1) % 3);
    bigAdd(1, i % 3, 0, (i - 1) % 3, 0, (i - 2) % 3);
  }
  bigAdd(0, (n + 1) % 3, 0, n % 3, 1, n % 3);
  for (int i = solution[0][(n + 1) % 3][0]; i >= 1; --i)
    printf("%d", solution[0][(n + 1) % 3][i]);
}

int main() {
  init();
  solve();
  return 0;
}
