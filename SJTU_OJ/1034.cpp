#include <iostream>
#include <stdio.h>

using namespace std;

int n, k, arr[400005];
int q[200005], head = 0, rear = 0;
int maxv = 2000000000;

void init() {
  scanf("%d%d", &n, &k);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    arr[i + n] = arr[i];
  }
}

void solve() {
  for (int i = 0; i < n + k - 1; ++i) {
    while (head < rear && arr[i] > arr[q[rear - 1]]) rear--;
    q[rear++] = i;
    while (head < rear && q[head] <= i - k) head++;
    if (i + 1 >= k && maxv > arr[q[head]]) maxv = arr[q[head]];
  }
  printf("%d", maxv);
}

int main() {
  init();
  solve();
  return 0;
}
