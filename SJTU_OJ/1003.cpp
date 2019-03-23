#include <iostream>
#include <stdio.h>

using namespace std;

int l, mp[105][105];
int q[10005], head = 0, rear = 0, dir[5] = {-1, 0, 1, 0, -1};

void init() {
  scanf("%d", &l);
  for (int i = 0; i < l; ++i) {
    for (int j = 0; j < l; ++j) {
      scanf("%d", &mp[i][j]);
      if (mp[i][j] == 1) {
        q[rear++] = i * l + j;
      }
    }
  }
}

void solve() {
  int cnt = 0;
  while (head != rear) {
    int sz = rear - head;
    for (int s = 0; s < sz; ++s) {
      int i = q[head] / l, j = q[head] % l;
      for (int d = 0; d < 4; ++d) {
        int ni = i + dir[d], nj = j + dir[d + 1];
        if (ni < 0 || ni >= l || nj < 0 || nj >= l) continue;
        if (mp[ni][nj]) continue;
        mp[ni][nj] = 1;
        q[rear++] = ni * l + nj;
      }
      head++;
    }
    cnt++;
  }
  printf("%d", cnt - 1);
}

int main() {
  init();
  solve();
  return 0;
}
