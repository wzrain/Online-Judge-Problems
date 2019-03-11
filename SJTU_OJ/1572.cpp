#include <iostream>
#include <stdio.h>

using namespace std;

int h[100005];
int tree[400005];
int n;
long long cnt = 0;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &h[i]);
  }
}

void update(int root, int t, int l, int r) {
  if (l == r) {
    tree[root] += 1;
    return;
  }
  int mid = (l + r) / 2;
  if (t > mid) update(root * 2 + 2, t, mid + 1, r);
  else update(root * 2 + 1, t, l, mid);
  tree[root] = tree[root * 2 + 1] + tree[root * 2 + 2];
}

int query(int root, int qs, int qe, int l, int r) {
  if (qs == l && qe == r) return tree[root];
  int mid = (l + r) / 2;
  if (mid < qs) return query(root * 2 + 2, qs, qe, mid + 1, r);
  else if (mid >= qe) return query(root * 2 + 1, qs, qe, l, mid);
  return query(root * 2 + 1, qs, mid, l, mid) +
         query(root * 2 + 2, mid + 1, qe, mid + 1, r);
}

void mergeTwoArr(int l, int r) {
  int mid = (l + r) / 2;
  int m1 = l, m2 = mid + 1, tmp[r - l + 1], idx = 0;
  while (m1 <= mid && m2 <= r) {
    if (h[m1] <= h[m2]) {
      tmp[idx++] = h[m1++];
    }
    else {
      tmp[idx++] = h[m2++];
      cnt += (mid - m1 + 1);
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
      //cnt += (r - mid);
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
  mergeTwoArr(l, r);
}

void segTreeSol() {
  for (int i = n - 1; i >= 0; --i) {
    if (h[i] != 1) {
      cnt += query(0, 0, h[i] - 2, 0, n - 1);
    }
    update(0, h[i] - 1, 0, n - 1);
  }
  printf("%lld", cnt);
}

void mergeSortSol() {
  mergeSort(0, n - 1);
  printf("%lld", cnt);
}

int main() {
  init();
  //segTreeSol();
  mergeSortSol();
  return 0;
}
