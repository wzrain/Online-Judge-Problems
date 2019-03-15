#include <iostream>
#include <stdio.h>

using namespace std;

struct pos {
  int x, y, step;
  pos(int xx = 0, int yy = 0, int s = 0) : x(xx), y(yy), step(s) {}
};

int n, m, mp[1005][1005];
int h2 = 0, r2 = 0, h3 = 0, r3 = 0;
pos q[1000005];
int dir[5] = {-1, 0, 1, 0, -1};
int mindis = 200000000;

void init() {
  scanf("%d%d", &m, &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      scanf("%d", &mp[i][j]);
      if (mp[i][j] == 2) q[r2++] = pos(i, j, 0);
    }
  }
}

void solve() {
  mp[q[h2].x][q[h2].y] = -1;
  pos st3;
  while (h2 != r2) {
    pos p = q[h2];
    for (int d = 0; d < 4; ++d) {
      int nx = p.x + dir[d], ny = p.y + dir[d + 1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
          mp[nx][ny] == 1 || mp[nx][ny] == -1 ||
          mp[nx][ny] >= 100) {
        continue;
      }
      if (mp[nx][ny] == 4) mp[nx][ny] = 100 + p.step + 1;
      else {
        if (mp[nx][ny] == 3) st3 = pos(nx, ny, 0);
        mp[nx][ny] = -1;
      }
      q[r2++] = pos(nx, ny, p.step + 1);
    }
    h2++;
  }

  q[r3++] = st3;
  mp[q[h3].x][q[h3].y] = -2;
  while (h3 != r3) {
    pos p = q[h3];
    for (int d = 0; d < 4; ++d) {
      int nx = p.x + dir[d], ny = p.y + dir[d + 1];
      if (nx < 0 || nx >= n || ny < 0 || ny >= m ||
          mp[nx][ny] == 1 || mp[nx][ny] == -2) {
        continue;
      }
      if (mp[nx][ny] >= 100 && mp[nx][ny] - 100 + p.step + 1 < mindis) {
        mindis = mp[nx][ny] - 100 + p.step + 1;
      }
      mp[nx][ny] = -2;
      q[r3++] = pos(nx, ny, p.step + 1);
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
