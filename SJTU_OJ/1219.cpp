#include <iostream>
#include <stdio.h>

using namespace std;

int n, h[200005], tmp[200005];
long long cnt = 0;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &h[i]);
}

int bisearch(int l, int r, int t) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (t < h[mid]) return bisearch(l, mid, t);
  else return bisearch(mid + 1, r, t);
}

void mergeTwoArr(int l, int mid, int r) {
  int m1 = l, m2 = mid + 1, idx = 0;
  while (m1 <= mid && m2 <= r) {
    if (h[m1] <= h[m2]) {
      tmp[idx++] = h[m1++];
    }
    else {
      if (h[mid] > 2 * h[m2]) {
        int ix = bisearch(m1, mid, 2 * h[m2]);
        cnt += (mid - ix + 1);
      }
      tmp[idx++] = h[m2++];
    }
  }
  if (m1 > mid) {
    for (int i = m2; i <= r; ++i) {
      tmp[idx++] = h[i];
    }
  }
  if (m2 > r) {
    for (int i = m1; i <= mid; ++i) {
      tmp[idx++] = h[i];
    }
  }
  for (int i = l; i <= r; ++i) {
    h[i] = tmp[i - l];
  }
}

void mergeSort(int l, int r) {
  if (l == r) return;
  int mid = (l + r) / 2;
  mergeSort(l, mid);
  mergeSort(mid + 1, r);
  mergeTwoArr(l, mid, r);
}

void mergeSortSol() {
  mergeSort(0, n - 1);
  printf("%lld", cnt);
}

int main() {
  init();
  mergeSortSol();
  return 0;
}
