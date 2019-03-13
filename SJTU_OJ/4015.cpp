#include <iostream>
#include <stdio.h>

using namespace std;

int a, b, n, round, f[1000005];

void init() {
  scanf("%d%d%d", &a, &b, &n);
  f[1] = f[2] = 1;
  round = n + 1;
}

void solve(){
  for (int i = 3; i <= n; ++i) {
    f[i] = ((a * f[i - 1]) % 7 + (b * f[i - 2]) % 7) % 7;
    if (f[i] == 1 && f[i - 1] == 1){
      round = i - 2;
      break;
    }
  }
  int idx = (n - 1) % round + 1;
  printf("%d", f[idx]);
}

int main() {
  init();
  solve();
  return 0;
}
