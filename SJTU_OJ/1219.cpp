#include <iostream>
#include <stdio.h>

using namespace std;

int n, h[200005], tmp[200005], tree[800005];
long long cnt = 0;

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i)scanf("%d", &h[i]);
}

void quicksort(int arr[], int low, int high) {
  if (low >= high) return;
  int first = low, last = high;
  int key = arr[first];
  while (first < last) {
    while (first < last && arr[last] >= key) --last;
    arr[first] = arr[last];
    while (first < last && arr[first] <= key) ++first;
    arr[last] = arr[first];
  }
  arr[first] = key;
  quicksort(arr, low, first - 1);
  quicksort(arr, first + 1, high);
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

int bisearch(int l, int r, int t) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (t < h[mid]) return bisearch(l, mid, t);
  else return bisearch(mid + 1, r, t);
}

void mergeTwoArr(int l, int mid, int r) {
  int m1 = l, m2 = mid + 1, idx = 0;
  //while (m1 <= mid && m2 <)
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

void segTreeSol() {
  for (int i = 0; i < n; ++i) tmp[i] = h[i];
  quicksort(h, 0, n - 1);
  for (int i = n - 1; i >= 0; --i) {
    int val = tmp[i], compval = tmp[i] / 2 + tmp[i] % 2 - 1;
    int compidx = bisearch(0, n - 1, compval) - 1;
    if (compidx >= 0) {
      cnt += query(0, 0, compidx, 0, n - 1);
    }
    int vidx = bisearch(0, n - 1, val) - 1;
    update(0, vidx, 0, n - 1);
  }
  printf("%lld", cnt);
}

void mergeSortSol() {
  mergeSort(0, n - 1);
  printf("%lld", cnt);
}

int main() {
  init();
  //mergeSortSol();
  segTreeSol();
  return 0;
}
