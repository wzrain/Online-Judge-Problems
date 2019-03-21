#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, parent[500005], cnt[500005], num[500005], opt;


void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    parent[i] = i;
    cnt[i] = 1;
  }
  num[1] = n;
  opt = 1;
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

void del(int x) {
  int px = Find(x);
  if (!cnt[px]) return;
  num[cnt[px]]--;
  if (!num[cnt[px]] && opt == cnt[px]) {
    for (int j = opt - 1; j > 0; --j) {
      if (num[j]) {
        opt = j;
        break;
      }
    }
  }
  cnt[px] = 0;
}

void Union(int a, int b) {
  int pa = Find(a), pb = Find(b);
  if (!cnt[pa] || !cnt[pb] || pa == pb) return;
  parent[pa] = pb;
  num[cnt[pb]]--;
  num[cnt[pa]]--;
  cnt[pb] += cnt[pa];
  num[cnt[pb]]++;
  if (cnt[pb] > opt) opt = cnt[pb];
}

int query(int p) {
  int c = 0;
  for (int i = opt; i > 0; --i) {
    c += num[i];
    if (c >= p) return i;
  }
  return 0;
}

void solve() {
  for (int u = 0; u < m; ++u) {
    char op[5];
    scanf("%s", op);
    if (op[0] == 'C') {
      int x, y;
      scanf("%d%d", &x, &y);
      Union(x, y);
    }
    else if (op[0] == 'D') {
      int x;
      scanf("%d", &x);
      del(x);
    }
    else if (op[0] == 'Q') {
      int p;
      scanf("%d", &p);
      printf("%d\n", query(p));
    }
  }
}

int main() {
  init();
  solve();
  return 0;
}
