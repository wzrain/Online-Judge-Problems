#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, parent[1005];
int ans[1005];

void bigPow(int x) {
  int len = 1, addtmp = 0;
  ans[0] = ans[1] = 1;
  for (int i = 0; i < x; ++i) {
    for (int j = 1; j <= len; ++j) {
      ans[j] = 2 * ans[j] + addtmp;
      addtmp = ans[j] / 10;
      if (ans[j] >= 10) ans[j] %= 10;
    }
    if (addtmp) ans[++len] = addtmp;
    addtmp = 0;
  }
  ans[0] = len;
}

void printAns() {
  int len = ans[0];
  for (int i = len; i > 0; --i) {
    printf("%d", ans[i]);
  }
}

int Find(int x) {
  int res = x;
  while (res != parent[res]) res = parent[res];
  while (x != res) {
    int tmp = parent[x];
    parent[x] = res;
    x = tmp;
  }
  return res;
}

void Union(int a, int b) {
  int pa = Find(a), pb = Find(b);
  if (pa != pb) parent[pa] = pb;
}

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) parent[i] = i;
  int a, b;
  for (int i = 0; i < m; ++i) {
    scanf("%d%d", &a, &b);
    Union(a, b);
  }
}

void solve() {
  int cnt = 0;
  for (int i = 1; i <= n; ++i) {
    if (parent[i] != i) cnt++;
  }
  bigPow(cnt);
  printAns();
}

int main() {
  init();
  solve();
  return 0;
}
