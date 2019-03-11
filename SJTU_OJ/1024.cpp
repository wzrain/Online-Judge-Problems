#include <iostream>
#include <stdio.h>

using namespace std;

int n, arr[10005];

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
}

void mergeTwoArr(int l, int r) {
  int mid = (l + r) / 2;
  int m1 = l, m2 = mid + 1, tmp[r - l + 1], idx = 0;
  while (m1 <= mid && m2 <= r) {
    if (arr[m1] <= arr[m2]) {
      tmp[idx++] = arr[m1++];
    }
    else tmp[idx++] = arr[m2++];
  }
  if (m1 > mid) {
    for (int i = m2; i <= r; ++i) {
      tmp[idx++] = arr[i];
    }
  }
  if (m2 > r) {
    for (int i = m1; i <= mid; ++i) {
      tmp[idx++] = arr[i];
    }
  }
  for (int i = l; i <= r; ++i) {
    arr[i] = tmp[i - l];
  }
}

void mergeSort(int l, int r) {
  if (l == r) return;
  int mid = (l + r) / 2;
  mergeSort(l, mid);
  mergeSort(mid + 1, r);
  mergeTwoArr(l, r);
}

void solve() {
  mergeSort(0, n - 1);
  for (int i = 0; i < n; ++i) {
    printf("%d ", arr[i]);
  }
}

int main() {
  init();
  solve();
  return 0;
}
