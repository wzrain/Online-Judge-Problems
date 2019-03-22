#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, cnt = 0, mp[505][505], dir[5] = {-1, 0, 1, 0, -1};

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &mp[i][j]);
    }
  }
}

void dfs(int i, int j) {
  mp[i][j] = -1;
  for (int d = 0; d < 4; ++d) {
    int ni = i + dir[d], nj = j + dir[d + 1];
    if (ni < 0 || ni >= n || nj < 0 || nj >= m || mp[ni][nj] == -1) continue;
    dfs(ni, nj);
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (mp[i][j] == 0) {
        cnt++;
        dfs(i, j);
      }
    }
  }
  printf("%d", cnt);
}

int main(){
  init();
  solve();
  return 0;
}
