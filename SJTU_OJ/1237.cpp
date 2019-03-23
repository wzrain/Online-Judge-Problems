#include <iostream>
#include <stdio.h>

using namespace std;

struct edge {
  int last;
  edge* next;
  edge(int l = 0) : last(l), next(NULL) {}
};

int n, m, degree[10005], q[10005], head = 0, rear = 0;
edge* graph[10005];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) graph[i] = new edge;
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    degree[a]++;
    edge* p = graph[b];
    while (p->next) p = p->next;
    p->next = new edge(a);
  }
}

void solve() {
  for (int i = 1; i <= n; ++i) {
    if (degree[i]) continue;
    q[rear++] = i;
  }
  int cnt = 0;
  while (head != rear) {
    int sz = rear - head;
    cnt++;
    for (int i = 0; i < sz; ++i) {
      edge* p = graph[q[head]];
      while (p->next) {
        int l = p->next->last;
        if (degree[l]) degree[l]--;
        if (!degree[l]) q[rear++] = l;
        p = p->next;
      }
      head++;
    }
  }
  printf("%d", cnt);
}

int main() {
  init();
  solve();
  return 0;
}
