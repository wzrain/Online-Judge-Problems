#include <iostream>
#include <stdio.h>

using namespace std;

int n, m, start, len, cnt = 0, visited[105], paths[105][105];

void init() {
  scanf("%d%d%d%d", &n, &m, &start, &len);
  for (int i = 0; i < m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    paths[a][++paths[a][0]] = b;
  }
  //visited[start] = 1;
}

void dfs(int s, int l) {
  if (visited[s]) return;
  if (l == len) {
    cnt++;
    return;
  }
  visited[s] = 1;
  for (int i = 1; i<= paths[s][0]; ++i) {
    //if (visited[paths[s][i]]) continue;
    //visited[paths[s][i]] = 1;
    dfs(paths[s][i], l + 1);
    //visited[paths[s][i]] = 0;
  }
  visited[s] = 0;
}

void solve() {
  dfs(start, 0);
  printf("%d", cnt);
}

int main() {
  init();
  solve();
  return 0;
}
