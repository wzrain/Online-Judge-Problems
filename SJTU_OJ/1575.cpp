#include <iostream>
#include <stdio.h>

using namespace std;

int l, n, m, arr[50005];

void init() {
  scanf("%d%d%d", &l, &n, &m);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &arr[i]);
  }
}

bool valid(int mid) {
  int cnt = 0, len = 0;
  for (int i = 1; i <= n; ++i) {
    int itv = arr[i] - arr[i - 1];
    len += itv;
    if (len <= mid) cnt++;
    else len = 0;
    if (cnt > m) return false;  // Here every interval is longer than mid, which means the shortest interval
                                // is larger than mid. But this condition directly makes the bisearch process
                                // eliminate all the values larger than mid (e = mid), which means all the
                                // values between mid and the current shortest interval length are invalid. 
                                // This is because the candidate lengths are not continuous, and there are 
                                // only n^2 possible values. Due to the strategy here, the values between mid 
                                // and the current shortest interval length are all not candidates. 
  }
  return true; // The result is definitely larger than mid (s = mid + 1).
}

void solve() {
  int s = 0, e = l;
  while (s < e) {
    int mid = (s + e) / 2;
    if (valid(mid)) s = mid + 1;
    else e = mid;
  }
  printf("%d", s);
}

int main() {
  init();
  solve();
  return 0;
}
