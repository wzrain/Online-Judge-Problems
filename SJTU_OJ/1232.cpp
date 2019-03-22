#include <iostream>
#include <stdio.h>
#include <cmath>

using namespace std;

int n, s, e, parent[1000005], path[1000005][4];
int total, res[1000005], cnt = 0, visited[1000005];

int getNeighbor(int x, int d) {
  int line = sqrt(x * 2);
  if (line * (line + 1) / 2 < x) line++;
  if (d == 0) {
    int nb = x - line;
    if (nb <= (line - 1) * (line - 2) / 2) return -1;
    return nb;
  }
  else if (d == 1) {
    int nb = x - line + 1;
    if (nb > line * (line - 1) / 2) return -1;
    return nb;
  }
  else if (d == 2) {
    int nb = x + line;
    if (nb > total) return -1;
    return nb;
  }
  else if (d == 3) {
    int nb = x + line + 1;
    if (nb > total) return -1;
    return nb;
  }
  return -1;
}

int Find(int x) {
  int res = x;
  while (res != parent[res]) res = parent[res];
  while (x != res) {
    int tmp = x;
    x = parent[x];
    parent[tmp] = res;
  }
  return res;
}

void Union(int a, int b) {
  int pa = Find(a), pb = Find(b);
  if (pa != pb) parent[pb] = pa;
}

void dfs(int x, bool &f) {
  if (f) return;
  if (x == e) {
    for (int i = 0; i < cnt; ++i) {
      printf("%d ", res[i]);
    }
    f = true;
    return;
  }
  for (int d = 0; d < 4; ++d) {
    int nb = getNeighbor(x, d);
    if (!path[x][d] || visited[nb]) continue;
    visited[nb] = 1;
    res[cnt++] = nb;
    dfs(nb, f);
    visited[nb] = 0;
    res[--cnt] = 0;
  }
}

void init() {
  scanf("%d%d%d", &n, &s, &e);
  total = n * (n + 1) / 2;
  for (int i = 1; i <= total; ++i) parent[i] = i;
}

void solve() {
  while (1) {
    int x, d;
    scanf("%d%d", &x, &d);
    int nb = getNeighbor(x, d);
    if (nb == -1) continue;
    Union(x, nb);
    path[x][d] = 1;
    path[nb][3 - d] = 1;
    if (Find(s) == Find(e)) {
      bool flag = false;
      visited[s] = 1;
      res[cnt++] = s;
      dfs(s, flag);
      return;
    }
  }
}

int main(){
  init();
  solve();
  return 0;
}
