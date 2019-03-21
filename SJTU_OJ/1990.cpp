#include <iostream>
#include <stdio.h>

using namespace std;

int h[4000005], hsize = 0, arr[2000005], idxes[2000005];
int timing[4000005];
int n, m;

void up(int i, int u) {
  int xi = h[i], pidx = i, idx = pidx >> 1;
  while (idx > 0 && arr[h[pidx]] <= arr[h[idx]]) {
    idxes[h[pidx]] = idx;
    idxes[h[idx]] = pidx;
    h[pidx] = h[idx];
    h[idx] = xi;
    pidx = idx;
    idx >>= 1;
  }
  timing[h[pidx]] = u;
}

void down(int i, int u) {
  int xi = h[i], pidx = i, idx;
  if (arr[h[pidx * 2]] == arr[h[pidx * 2 + 1]]) {
    idx = timing[h[pidx * 2]] < timing[h[pidx * 2 + 1]] ? pidx * 2 + 1 : pidx * 2;
  }
  else idx = arr[h[pidx * 2]] < arr[h[pidx * 2 + 1]] ? pidx * 2 : pidx * 2 + 1;
  while (idx <= hsize && arr[h[pidx]] > arr[h[idx]]) {
    idxes[h[pidx]] = idx;
    idxes[h[idx]] = pidx;
    h[pidx] = h[idx];
    h[idx] = xi;
    pidx = idx;
    if (arr[h[idx * 2]] == arr[h[idx * 2 + 1]]) {
      idx = timing[h[idx * 2]] < timing[h[idx * 2 + 1]] ? idx * 2 + 1 : idx * 2;
    }
    else idx = arr[h[idx * 2]] < arr[h[idx * 2 + 1]] ? idx * 2 : idx * 2 + 1;
  }
  timing[h[pidx]] = u;
}

void push(int x, int u) {
  h[++hsize] = x;
  idxes[x] = hsize;
  up(hsize, u);
}

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
    push(i, i);
  }
}

void solve() {
  for (int u = 1; u <= m; ++u) {
    int x, y;
    scanf("%d%d", &x, &y);
    int idx = idxes[x];
    arr[x] += y;
    if (y > 0) down(idx, u + n);
    else up(idx, u + n);
    printf("%d\n", h[1]);
  }
}

int main() {
  init();
  solve();
  return 0;
}
