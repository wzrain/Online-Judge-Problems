#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
  int x, y;
  node(int xx = 0, int yy = 0) : x(xx), y(yy) {}
};

int n, cnt = 0;
node s[100005], s1[100005], s2[100005];

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s1[i].y);
    s1[i].x = i + 1;
  }
  for (int i = 0; i < n; ++i) {
    scanf("%d", &s2[i].y);
    s2[i].x = i + 1;
  }
}

void quicksort(node s[], int low, int high) {
  if (low >= high) return;
  int first = low, last = high;
  node key = s[low];
  while (first < last) {
    while (first < last && s[last].y >= key.y) last--;
    s[first] = s[last];
    while (first < last && s[first].y <= key.y) first++;
    s[last] = s[first];
  }
  s[first] = key;
  quicksort(s, low, first - 1);
  quicksort(s, first + 1, high);
}

void mergeTwoArr(int l, int r) {
  int mid = (l + r) / 2, i = l, j = mid + 1;
  int tmp[r - l + 1], idx = 0;
  while (i <= mid && j <= r) {
    if (s[i].x > s[j].x) {
      cnt += (mid - i + 1);
      cnt %= 99999997;
      tmp[idx++] = s[j++].x;
    }
    else tmp[idx++] = s[i++].x;
  }
  while (i <= mid) tmp[idx++] = s[i++].x;
  while (j <= r) tmp[idx++] = s[j++].x;
  for (int i = 0; i < idx; ++i) {
    s[i + l].x = tmp[i];
  }
}

void mergeSort(int l, int r) {
  if (l >= r) return;
  int mid = (l + r) / 2;
  mergeSort(l, mid);
  mergeSort(mid + 1, r);
  mergeTwoArr(l, r);
}

void solve() {
  quicksort(s1, 0, n - 1);
  quicksort(s2, 0, n - 1);
  for (int i = 0; i < n; ++i) {
    s[i].x = s1[i].x;
    s[i].y = s2[i].x;
  }
  quicksort(s, 0, n - 1);
  mergeSort(0, n - 1);
  printf("%d", cnt);
}

int main() {
  init();
  solve();
  return 0;
}
