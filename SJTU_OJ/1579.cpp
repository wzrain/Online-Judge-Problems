#include <iostream>
#include <stdio.h>

using namespace std;

char A[1005], B[1005];
int n, m;

int LCS[1005][1005];

int main() {
  scanf("%d%d", &n, &m);
  scanf("%s", A);
  scanf("%s", B);
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j <= m; ++j) {
      if (A[i - 1] == B[j - 1]) {
        LCS[i][j] = LCS[i - 1][j - 1] + 1;
      }
      else {
        LCS[i][j] = (LCS[i - 1][j] > LCS[i][j - 1] ? LCS[i - 1][j] : LCS[i][j - 1]);
      }
    }
  }
  printf("%d", LCS[n][m]);
}
