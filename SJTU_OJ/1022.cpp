#include <iostream>
#include <stdio.h>

using namespace std;

int remain[1000005];

int main() {
  int i = 1, j = 1,cnt = 3;
  remain[1] = remain[2] = 1;
  while (1) {
    int tmp = i + j;
    i = j;
    j = tmp % 2010;
    if (i == 1 && j == 1) break;
    remain[cnt++] = j;
  }
  int loop = cnt-2;
  long long N;
  scanf("%lld", &N);
  int idx = N % loop;
  printf("%d", remain[idx]);
  return 0;
}
