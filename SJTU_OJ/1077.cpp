#include <iostream>
#include <stdio.h>

using namespace std;

int n;
int ms[35][35], root[35][35];

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &ms[i][i]);
    root[i][i] = i;
  }
}

void printTree(int i, int j) {
  if (i > j) return;
  if (i == j) {
    printf("%d ", root[i][j]);
    return;
  }
  printf("%d ", root[i][j]);
  printTree(i, root[i][j] - 1);
  printTree(root[i][j] + 1, j);
}

void solve() {
  for (int w = 1; w < n; ++w) {
    for (int i = 1; i <= n - w; ++i) {
      for (int r = i; r <= i + w; ++r) {
        int l = 1, h = 1, tmp;
        if (r != i) l = ms[i][r - 1];
        if (r != i + w) h = ms[r + 1][i + w];
        tmp = l * h + ms[r][r];
        if (tmp > ms[i][i + w]) {
          ms[i][i + w] = tmp;
          root[i][i + w] = r;
        }
      }
    }
  }
  printf("%d\n", ms[1][n]);
  printTree(1, n);
}

int main() {
  init();
  solve();
  return 0;
}
