#include <iostream>
#include <stdio.h>

using namespace std;

int arr[200005], q[200005];
int k, n, head = 0, rear = 0;

void init() {
  scanf("%d%d", &k, &n);
  for (int i = 0; i < n; ++i) scanf("%d", &arr[i]);
}

void solve() {
  for (int i = 0; i < n; ++i) {
    while (head != rear && arr[q[rear - 1]] < arr[i]) rear--;
    q[rear++] = i;
    while (q[head] <= i - k) head++;
    if (i >= k - 1) printf("%d ", arr[q[head]]);
  }
}

int main() {
  init();
  solve();
  return 0;
}
