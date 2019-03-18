#include <iostream>
#include <stdio.h>

using namespace std;

int n, arr[1000005], last[1000005], length = 0;

void init() {
  scanf("%d", &n);
  for (int i = n - 1; i >= 0; --i) scanf("%d", &arr[i]);
}

int bisearch(int l, int r, int t) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (t < last[mid]) return bisearch(l, mid, t);
  else return bisearch(mid + 1, r, t);
}

void solve() {
  for (int i = 0; i < n; ++i) {
    int idx = bisearch(0, length, arr[i]);
    last[idx] = arr[i];
    if (idx == length) length++;
  }
  printf("%d\n", length);

  length = 0;
  last[0] = 0;
  for (int i = n - 1; i >= 0; --i) {
    int idx = bisearch(0, length, arr[i]);
    last[idx] = arr[i];
    if (idx > 0 && last[idx - 1] == arr[i]) continue;
    if (idx == length) length++;
  }
  printf("%d", length);
}

int main() {
  init();
  solve();
  return 0;
}
