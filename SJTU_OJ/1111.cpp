#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char pre[1005], mid[1005], num;
int p[1005], m[1005];
int l[1005], r[1005];
int q[1005];

void init() {
  scanf("%s", pre);
  scanf("%s", mid);
  num = strlen(pre);
  for (int i = 0; i < num; ++i) {
    p[i] = pre[i] - 'A' + 1;
    m[i] = mid[i] - 'A' + 1;
  }
}

void findSub(int pi, int ml, int mr) {

  int mi;
  for (int i = ml; i <= mr; ++i) {
    if (m[i] == p[pi]) {
       mi = i;
       break;
    }
  }
  int lsubsize = mi - ml, rsubsize =  mr - mi;
  if (lsubsize == 0) l[m[mi]] = 0;
  else {
    l[m[mi]] = p[pi + 1];
    findSub(pi + 1, ml, mi - 1);
  }
  if (rsubsize == 0) r[m[mi]] = 0;
  else {
    r[m[mi]] = p[pi + lsubsize + 1];
    findSub(pi + lsubsize + 1, mi + 1, mr);
  }
}

void solve() {
  findSub(0, 0, num - 1);
  int head = 0, rear = 0, cnt = 0;;
  q[rear++] = p[0];
  while(head != rear) {
    q[rear++] = l[q[head]];
    q[rear++] = r[q[head]];
    if (q[head] == 0) {
      printf("%s ", "NULL");
    }
    else {
      char c = q[head] + 'A' - 1;
      printf("%c ", c);
      cnt++;
    }
    head++;
    if (cnt == num) break;
  }
}

int main() {
  init();
  solve();
  return 0;
}
