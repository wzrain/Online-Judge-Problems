#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
  int x, y, step;
  node(int xx = 0, int yy = 0, int s = 0) : x(xx), y(yy), step(s) {}
};

int n, m, x1, y1, x2, y2;
char mp[105][105];
int head = 0, rear = 0, visited[105][105], dir[5] = {-1, 0, 1, 0, -1};
node q[10005];

void init() {
  scanf("%d%d%d%d%d%d", &n, &m, &x1, &y1, &x2, &y2);
  for (int i = 0; i < n; ++i) scanf("%s", mp[i]);
}

void solve() {
  q[rear++] = node(x1 - 1, y1 - 1, 0);
  visited[x1 - 1][y1 - 1] = 1;
  while (head != rear) {
    char c = mp[q[head].x][q[head].y];
    for (int d = 0; d < 4; ++d) {
      int nx = q[head].x + dir[d], ny = q[head].y + dir[d + 1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
      if (mp[nx][ny] == '*' || visited[nx][ny]) continue;
      if (c == '|' && dir[d + 1] != 0) continue;
      if (c == '-' && dir[d] != 0) continue;
      if (dir[d] != 0 && mp[nx][ny] == '-') continue;
      if (dir[d + 1] != 0 && mp[nx][ny] == '|') continue;
      if (nx == x2 - 1 && ny == y2 - 1) {
        printf("%d", q[head].step + 1);
        return;
      }
      visited[nx][ny] = 1;
      q[rear++] = node(nx, ny, q[head].step + 1);
    }
    head++;
  }
  printf("%d", -1);
}

int main(){
  init();
  solve();
  return 0;
}
