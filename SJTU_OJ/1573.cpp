#include <iostream>
#include <stdio.h>

using namespace std;

int n, m;
int num[100005], color[100005];
int score = 0;
int numsum[2][100005], indexsum[2][100005], indexnum[2][100005];

void init() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) scanf("%d", &num[i]);
  for (int i = 1; i <= n; ++i) scanf("%d", &color[i]);
}

void solve() {
  for (int i = 1; i<=n; ++i) {
    numsum[i % 2][color[i]] += num[i];
    numsum[i % 2][color[i]] %= 10007;
    indexsum[i % 2][color[i]] += i;
    indexsum[i % 2][color[i]] %= 10007;
    indexnum[i % 2][color[i]]++;
  }
  for (int i = 1; i <= m; ++i) {
    for (int j = 0; j <= 1; ++j) {
      score += ((numsum[j][i] * indexsum[j][i]) % 10007);
      score %= 10007;
    }
  }
  for (int i = 1; i <= n; ++i) {
    score += (((indexnum[i % 2][color[i]] - 2) * num[i] % 10007) * i) % 10007;
    score %= 10007;
  }
  printf("%d", score);
}

int main() {
  init();
  solve();
  return 0;
}
