#include <iostream>
#include <stdio.h>

using namespace std;

int n, bd[15][15], cvstd[15], lvstd[30], rvstd[30];
int cnt = 0, res[15];

void dfs(int idx) {
  if (idx == n) {
    cnt++;
    if (cnt <= 3) {
      for (int i = 0; i < n; ++i) printf("%d ", res[i]);
      printf("%c", '\n');
    }
    return;
  }
  for (int c = 0; c < n; ++c) {
    if (cvstd[c] || lvstd[c + idx] || rvstd[n + idx - c]) continue;
    res[idx] = c + 1;
    cvstd[c] = lvstd[c + idx] = rvstd[n + idx - c] = 1;
    dfs(idx + 1);
    cvstd[c] = lvstd[c + idx] = rvstd[n + idx - c] = 0;
    res[idx] = 0;
  }
}

void solve() {
  scanf("%d", &n);
  dfs(0);
  printf("%d", cnt);
}

int main() {
  solve();
  return 0;
}
