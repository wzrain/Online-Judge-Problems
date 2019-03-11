#include <iostream>
#include <stdio.h>

using namespace std;

int h[100005];
int tree[400005];
int n;

void update(int root, int t, int l, int r) {
  if (l == r) {
    tree[root] += 1;
    return;
  }
  int mid = (l + r) / 2;
  if (t > mid) update(root * 2 + 2, t, mid + 1, r);
  else update(root * 2 + 1, t, l, mid);
  tree[root] = tree[root * 2 + 1] + tree[root * 2 + 2];
}

int query(int root, int qs, int qe, int l, int r) {
  if (qs == l && qe == r) return tree[root];
  int mid = (l + r) / 2;
  if (mid < qs) return query(root * 2 + 2, qs, qe, mid + 1, r);
  else if (mid >= qe) return query(root * 2 + 1, qs, qe, l, mid);
  return query(root * 2 + 1, qs, mid, l, mid) +
         query(root * 2 + 2, mid + 1, qe, mid + 1, r);
}

void segTreeSol() {
  long long cnt = 0;
  for (int i = n - 1; i >= 0; --i) {
    if (h[i] != 1) {
      cnt += query(0, 0, h[i] - 2, 0, n - 1);
    }
    update(0, h[i] - 1, 0, n - 1);
  }
  printf("%lld", cnt);
}

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
}

int main() {
  init();
  segTreeSol();
  return 0;
}
