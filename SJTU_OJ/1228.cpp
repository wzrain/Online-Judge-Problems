#include <iostream>
#include <stdio.h>

using namespace std;

int n, mat[405][405], colsum[405][405], dp[405][405][2];
long long odd = 0, even = 0;

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      scanf("%d", &mat[i][j]);
      mat[i][j] = mat[i][j] & 1;
    }
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= n; ++j) {
      colsum[i][j] = mat[i][j] + colsum[i - 1][j];
    }
  }
}

void solve() {
  for (int c = 1; c <= n; ++c) {
    for (int i = 1; i <= n; ++i) {
      for (int j = i; j <= n; ++j) {
        int sum = colsum[j][c] - colsum[i - 1][c];
        int oe = sum & 1;
        int ot = oe + dp[i][j][1 - oe];
        int et = 1 - oe + dp[i][j][oe];
        dp[i][j][1] = ot;
        dp[i][j][0] = et;
        odd += dp[i][j][1];
        even += dp[i][j][0];
      }
    }
  }
  printf("%lld %lld", odd, even);
}

int main() {
  init();
  solve();
  return 0;
}
