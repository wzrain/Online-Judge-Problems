#include <iostream>
#include <stdio.h>

using namespace std;

int n, l[100005], r[1000005], f[100005], root;
int q[1000005], head = 0, rear = 0;

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", &l[i], &r[i]);
    f[l[i]] = i;
    f[r[i]] = i;
  }
  for (int i = 1; i <= n; ++i) {
    if (!f[i]) {
      root = i;
      break;
    }
  }
  q[rear++] = root;
}

bool isCBT() {
  bool reached = false;
  while (head != rear) {
    int lc = l[q[head]], rc = r[q[head]];
    if (!lc && rc) return false;
    if (reached && lc) return false;
    if (!rc) reached = true;
    if (lc) q[rear++] = lc;
    if (rc) q[rear++] = rc;
    head++;
  }
  return true;
}

bool isCBT2() {
  while(head != rear) {
    int lc = l[q[head]], rc = r[q[head]];
    if (lc) q[rear++] = lc;
    else return rear == n;
    if (rc) q[rear++] = rc;
    else return rear == n;
    head++;
  }
  return true;
}

void solve() {
  if (isCBT2()) printf("%c", 'Y');
  else printf("%c", 'N');
}

int main() {
  init();
  solve();
  return 0;
}
