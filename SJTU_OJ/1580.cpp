#include <iostream>
#include <stdio.h>

using namespace std;

int x[1000005];
int last[1000005];
int length = 0;

int BiSearch(int t, int l, int r) {
  if (l == r) return l;
  int mid = (l + r) / 2;
  if (t >= last[mid]) return BiSearch(t, mid + 1, r);
  else return BiSearch(t, l, mid);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d", &x[i]);
    int idx = BiSearch(x[i], 1, length + 1);
    if (last[idx - 1] == x[i]) continue; // strictly increasing
    last[idx] = x[i];
    if (idx == length + 1){
      length++;
    }
  }
  printf("%d", length);
}
