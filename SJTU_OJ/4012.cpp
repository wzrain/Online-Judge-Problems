#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, h[20005], sum = 0, hsize = 0;

void up(int i) {
  int x = h[i], pidx = i, idx = i >> 1;
  while (idx > 0 && x < h[idx]) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx >>= 1;
  }
}

void down(int i) {
  int x = h[i], pidx = i;
  int idx = (h[i * 2 + 1] > h[i * 2]) ? i * 2 : i * 2 + 1;
  while (idx <= hsize && x > h[idx]) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx = (h[idx * 2 + 1] > h[idx * 2]) ? idx * 2 : idx * 2 + 1;
  }
}

int pop() {
  int res = h[1];
  h[1] = h[hsize--];
  down(1);
  return res;
}

void ins(int x) {
  h[++hsize] = x;
  up(hsize);
}

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    int x;
    scanf("%d", &x);
    ins(x);
  }
}

void solve() {
  while (hsize > 1) {
    int i1 = pop(), i2 = pop();
    sum += (i1 + i2);
    ins(i1 + i2);
  }
  printf("%d", sum);
}

int main() {
  init();
  solve();
  return 0;
}
