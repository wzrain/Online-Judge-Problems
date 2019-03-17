#include <iostream>
#include <stdio.h>
#include <algorithm>

using namespace std;

int n, k, arr[100005], sa[100005];
int tree[12][400005];
int idxes[100005];

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

void init() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    sa[i] = arr[i];
  }
  quicksort(sa, 0, n - 1);
}

int bisearch(int l, int r, int t) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (t < sa[mid]) return bisearch(l, mid, t);
  else return bisearch(mid + 1, r, t);
}

int query(int root, int l, int r, int qs, int qe, int k) {
  if (l == qs && qe == r) return tree[k][root];
  int mid = (l + r) / 2;
  if (mid < qs) return query(root * 2 + 2, mid + 1, r, qs, qe, k);
  else if (mid >= qe) return query(root * 2 + 1, l, mid, qs, qe, k);
  return (query(root * 2 + 1, l, mid, qs, mid, k) +
         query(root * 2 + 2, mid + 1, r, mid + 1, qe, k)) % 1000000007;
}

void update(int root, int l, int r, int t, int d, int k) {
  if (l == r) {
    tree[k][root] += d;
    tree[k][root] %= 1000000007;
    return;
  }
  int mid = (l + r) / 2;
  if (t <= mid) update(root * 2 + 1, l, mid, t, d, k);
  else update(root * 2 + 2, mid + 1, r, t, d, k);
  tree[k][root] = (tree[k][root * 2 + 1] + tree[k][root * 2 + 2]) % 1000000007;
}

void solve() {
  for (int i = 0; i < n; ++i) {
    int idx = bisearch(0, n - 1, arr[i]) - 1;
    if (arr[i] == sa[n - 1]) idx = n - 1;
    idxes[i] = idx;
  }
  for (int i = n - 1; i >= 0; --i) {
    for (int ik = 2; ik <= k; ++ik) {
      int idx = idxes[i];
      if (idx >= 1) {
        int cnt = query(0, 0, n - 1, 0, idx - 1, ik - 1) % 1000000007;
        update(0, 0, n - 1, idx, cnt, ik);
      }
      if (ik == 2) update(0, 0, n - 1, idx, 1, ik - 1);
    }
  }
  printf("%d", tree[k][0]);
}

int main() {
  init();
  solve();
  return 0;
}
