#include <iostream>
#include <stdio.h>

using namespace std;

char mat[10][10];
int hcnt = 0, total = 0;
int visited[30], dir[5] = {-1, 0, 1, 0, -1}, path[7];

void init() {
  for (int i = 0; i < 5; ++i) scanf("%s", mat[i]);
}

bool bfs() {
  int head = 0, rear = 0, cnt = 0;
  int q[10];
  q[rear++] = path[0];
  cnt++;
  visited[path[0]] = 1;
  while (head != rear) {
    for (int d = 0; d < 4; ++d) {
      int ni = q[head] / 5 + dir[d], nj = q[head] % 5 + dir[d + 1];
      int nidx = 5 * ni + nj;
      if (ni >= 0 && ni < 5 && nj >= 0 && nj < 5 && !visited[nidx]) {
        for (int a = 0; a < 7; ++a) {
          if (path[a] == nidx) {
            q[rear++] = nidx;
            cnt++;
            visited[nidx] = 1;
          }
        }
      }
    }
    head++;
  }
  if (cnt == 7) return true;
  else return false;
}

void solve() {
  for (int i1 = 0; i1 < 19; ++i1) {
  path[0] = i1;
  if (mat[i1 / 5][i1 % 5] == 'H') hcnt++;
  for (int i2 = i1 + 1; i2 < 20; ++i2) {
  path[1] = i2;
  if (mat[i2 / 5][i2 % 5] == 'H') hcnt++;
  for (int i3 = i2 + 1; i3 < 21; ++i3) {
  path[2] = i3;
  if (mat[i3 / 5][i3 % 5] == 'H') hcnt++;
  for (int i4 = i3 + 1; i4 < 22; ++i4) {
  path[3] = i4;
  if (mat[i4 / 5][i4 % 5] == 'H') hcnt++;
  if (hcnt >= 4) {
    if (mat[i4 / 5][i4 % 5] == 'H') hcnt--;
    continue;
  }
  for (int i5 = i4 + 1; i5 < 23; ++i5) {
  path[4] = i5;
  if (mat[i5 / 5][i5 % 5] == 'H') hcnt++;
  if (hcnt >= 4) {
    if (mat[i5 / 5][i5 % 5] == 'H') hcnt--;
    continue;
  }
  for (int i6 = i5 + 1; i6 < 24; ++i6) {
  path[5] = i6;
  if (mat[i6 / 5][i6 % 5] == 'H') hcnt++;
  if (hcnt >= 4) {
    if (mat[i6 / 5][i6 % 5] == 'H') hcnt--;
    continue;
  }
  for (int i7 = i6 + 1; i7 < 25; ++i7) {
    path[6] = i7;
    if (mat[i7 / 5][i7 % 5] == 'H') hcnt++;
    if (hcnt >= 4) {
      if (mat[i7 / 5][i7 % 5] == 'H') hcnt--;
      continue;
    }
    for (int i = 0; i < 7; ++i) visited[path[i]] = 0;
    if (bfs()) total++;
    if (mat[i7 / 5][i7 % 5] == 'H') hcnt--;
  }
  if (mat[i6 / 5][i6 % 5] == 'H') hcnt--;
  }
  if (mat[i5 / 5][i5 % 5] == 'H') hcnt--;
  }
  if (mat[i4 / 5][i4 % 5] == 'H') hcnt--;
  }
  if (mat[i3 / 5][i3 % 5] == 'H') hcnt--;
  }
  if (mat[i2 / 5][i2 % 5] == 'H') hcnt--;
  }
  if (mat[i1 / 5][i1 % 5] == 'H') hcnt--;
  }
  printf("%d", total);
}

int main() {
  init();
  solve();
  return 0;
}
