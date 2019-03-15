#include <iostream>
#include <stdio.h>

using namespace std;

struct pos {
  int x, y, step;
  pos(int xx = 0, int yy = 0, int s = 0) : x(xx), y(yy), step(s) {}
};

int n, m, mp[1005][1005], visited[1005][1005];
int h2 = 0, r2 = 0, h3 = 0, r3 = 0;
pos q2[1000005], q3[1000005];
int dir[5] = {-1, 0, 1, 0, -1};
int mindis = 200000000;

void init() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &mp[i][j]);
      if (mp[i][j] == 2) q2[r2++] = pos(i, j, 0);
      if (mp[i][j] == 3) q3[r3++] = pos(i, j, 0);
    }
  }
}

void solve() {
  visited[q2[h2].x][q2[h2].y] = 1;
  while (h2 != r2) {
    pos p = q2[h2];
    if (mp[p.x][p.y] == 4) {
      mp[p.x][p.y] = 100 + p.step;
    }
    for (int d = 0; d < 4; ++d) {
      int nx = p.x + dir[d], ny = p.y + dir[d + 1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
          mp[nx][ny] == 1 || visited[nx][ny]) {
        continue;
      }
      visited[nx][ny] = 1;
      q2[r2++] = pos(nx, ny, p.step + 1);
    }
    h2++;
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      visited[i][j] = 0;
    }
  }
  visited[q3[h3].x][q3[h3].y] = 1;
  while (h3 != r3) {
    pos p = q3[h3];
    if (mp[p.x][p.y] >= 100 && mp[p.x][p.y] - 100 + p.step < mindis) {
      mindis = mp[p.x][p.y] - 100 + p.step;
    }
    for (int d = 0; d < 4; ++d) {
      int nx = p.x + dir[d], ny = p.y + dir[d + 1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
          mp[nx][ny] == 1 || visited[nx][ny]) {
        continue;
      }
      //mp[nx][ny] = -2;
      visited[nx][ny] = 1;
      q3[r3++] = pos(nx, ny, p.step + 1);
    }
    h3++;
  }
  printf("%d", mindis);
}

int main() {
  init();
  solve();
  return 0;
}
