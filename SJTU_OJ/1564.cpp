#include <iostream>
#include <stdio.h>

using namespace std;

int b[6][6], si, sj, ei, ej, dir[5] = {-1, 0, 1, 0, -1}, visited[6][6];
int mc = 2000000000;
int cnt = 0;

void dfs(int i, int j, int tc) {
  if (cnt >= mc) return;
  if (i == ei && j == ej) {
    if (mc > cnt) mc = cnt;
    return;
  }
  for (int d = 0; d < 4; ++d) {
    int ni = i + dir[d], nj = j + dir[d + 1];
    if (ni < 0 || ni >= 6 || nj < 0 || nj >= 6 || visited[ni][nj])
      continue;
    visited[ni][nj] = 1;
    int cost = tc * b[ni][nj];
    cnt += cost;
    dfs(ni, nj, cost % 4 + 1);
    cnt -= cost;
    visited[ni][nj] = 0;
  }
}

void solve() {
  int num;
  scanf("%d", &num);
  for (int n = 0; n < num; ++n){
    for (int i = 0; i < 6; ++i) {
      for (int j = 0; j < 6; ++j) {
        scanf("%d", &b[i][j]);
        visited[i][j] = 0;
      }
    }
    scanf("%d%d%d%d", &si, &sj, &ei, &ej);
    visited[si][sj] = 1;
    cnt = 0;
    dfs(si, sj, 1);
    printf("%d\n", mc);
  }
}

int main(){
  solve();
  return 0;
}
