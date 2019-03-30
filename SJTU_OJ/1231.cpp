#include <iostream>
#include <stdio.h>

using namespace std;

int n, x, y, root, p[100005], l[100005], r[100005], level[100005];

void init() {
  scanf("%d%d%d", &n, &x, &y);
  for (int i = 1; i <= n; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    l[i] = a;
    r[i] = b;
    p[a] = p[b] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (!p[i]) {
      root = i;
      break;
    }
  }
}

void setLevel(int rt, int lv) {
  level[rt] = lv;
  if (l[rt]) setLevel(l[rt], lv + 1);
  if (r[rt]) setLevel(r[rt], lv + 1);
}

void solve() {
  setLevel(root, 1);
  while (level[x] < level[y]) y = p[y];
  while (level[y] < level[x]) x = p[x];
  while (x != y) {
    x = p[x];
    y = p[y];
  }
  printf("%d", x);
}

int lca(int rt) {
  if (!rt || rt == x || rt == y) return rt;
  int lf = lca(l[rt]), rg = lca(r[rt]);
  if (lf && rg) return rt;
  if (!lf) return rg;
  return lf;
}

void solveRecur() {
  printf("%d", lca(root));
}

int main() {
  init();
  //solve();
  solveRecur();
  return 0;
}
