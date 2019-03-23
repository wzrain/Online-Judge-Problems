#include <iostream>
#include <stdio.h>

using namespace std;

struct edge {
  int x, y, v;
  edge(int xx = 0, int yy = 0, int vv = 0) : x(xx), y(yy), v(vv) {}
};

int n, m, parent[10005], total = 0, cnt = 0;
edge e[100005];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < m; ++i) scanf("%d%d%d", &e[i].x, &e[i].y, &e[i].v);
  for (int i = 1; i <= n; ++i) parent[i] = i;
}

void quicksort(int low, int high) {
  if (low >= high) return;
  int first = low, last = high;
  edge key = e[low];
  while (first < last) {
    while (first < last && e[last].v >= key.v) last--;
    e[first] = e[last];
    while (first < last && e[first].v <= key.v) first++;
    e[last] = e[first];
  }
  e[first] = key;
  quicksort(low, first - 1);
  quicksort(first + 1, high);
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

bool Union(int a, int b) {
  int pa = Find(a), pb = Find(b);
  if (pa == pb) return false;
  parent[pb] = pa;
  return true;
}

void solve() {
  quicksort(0, m - 1);
  for (int i = 0; i < m; ++i) {
    if (!Union(e[i].x, e[i].y)) continue;
    total += e[i].v;
    cnt++;
    if (cnt == n) break;
  }
  printf("%d", total);
}

int main() {
  init();
  solve();
  return 0;
}
