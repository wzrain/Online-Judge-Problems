#include <iostream>
#include <stdio.h>
#define INF 2147483647

using namespace std;

struct edge {
  int last, val;
  edge* next;
  edge(int l = 0, int v = 0) : last(l), val(v), next(NULL) {}
};

int n, m, start, finish, dis[10005], pre[10005], sol[10005], num[10005];
int h[20005], hsize = 0, hidx[10005];
edge* graph[200005];

void init() {
  scanf("%d%d%d%d", &n, &m, &start, &finish);
  for (int i = 1; i <= n; ++i) graph[i] = new edge;
  h[++hsize] = start;
  hidx[start] = hsize;
  for (int i = 1; i <= n; ++i) {
    if (i == start) continue;
    dis[i] = INF;
    h[++hsize] = i;
    hidx[i] = hsize;
  }
  for (int i = 0; i < m; ++i) {
    int s, f, v;
    scanf("%d%d%d", &s, &f, &v);
    edge* p = graph[s];
    while (p->next) p = p->next;
    p->next = new edge(f, v);
  }
}

void up(int i) {
  int x = h[i], pidx = i, idx = i >> 1;
  while (idx > 0 && dis[h[idx]] > dis[x]) {
    hidx[h[idx]] = pidx;
    hidx[h[pidx]] = idx;
    h[pidx] = h[idx];
    h[idx] =  x;
    pidx = idx;
    idx >>= 1;
  }
}

void down(int i) {
  int x = h[i], pidx = i, idx = (dis[h[i * 2]] < dis[h[i * 2 + 1]]) ? i * 2 : i * 2 + 1;
  while (idx <= hsize && dis[h[idx]] < dis[x]) {
    hidx[h[idx]] = pidx;
    hidx[h[pidx]] = idx;
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx = (dis[h[idx * 2]] < dis[h[idx * 2 + 1]] ? idx * 2 : idx * 2 + 1);
  }
}

int pop() {
  int res = h[1];
  h[1] = h[hsize--];
  hidx[h[1]] = 1;
  down(1);
  return res;
}

void relax(int pti) {
  int hi = hidx[pti];
  up(hi);
}

void solve() {
  int pt = pop();
  while (pt != finish) {
    edge* p = graph[pt];
    while (p->next) {
      int pi = p->next->last, pv = p->next->val;
      if (dis[pt] + pv < dis[pi]) {
        dis[pi] = dis[pt] + pv;
        relax(pi);
        pre[pi] = pt;
        num[pi] = num[pt] + 1;
      }
      else if (dis[pt] + pv == dis[pi]) {
        if (num[pi] > num[pt] + 1) {
          num[pi] = num[pt] + 1;
          pre[pi] = pt;
        }
      }
      p = p->next;
    }
    pt = pop();
  }
  printf("%d\n", dis[pt]);
  int cnt = 0;
  while (pt) {
    sol[cnt++] = pt;
    pt = pre[pt];
  }
  for (int i = cnt - 1; i >= 0; --i) printf("%d ", sol[i]);
}

int main() {
  init();
  solve();
  return 0;
}
