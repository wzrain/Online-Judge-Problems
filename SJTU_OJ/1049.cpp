#include <iostream>
#include <stdio.h>

using namespace std;

int t, n, m, train[1005];
int stk[1005], top = 0;

bool schedule() {
  int idx = 0;
  for (int i = 0; i < n; ++i) {
    if (train[idx] == i) {
      idx++;
      while (top > 0 && train[idx] == stk[top - 1]) {
        idx++;
        stk[--top] = 0;
      }
      continue;
    }
    if (top < m) {
      stk[top++] = i;
    }
    else return false;
  }
  if (idx == n)return true; // whether trains in the stack in the end can get out in the correct order
  return false;
}

void solve() {
  scanf("%d", &t);
  for (int j = 0; j < t; ++j) {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &train[i]);
    if (schedule()) printf("%s\n", "YES");
    else printf("%s\n", "NO");
    top = 0;
  }
}

int main() {
  solve();
  return 0;
}
