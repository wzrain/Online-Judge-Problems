#include <iostream>
#include <stdio.h>

using namespace std;

int n, arr[205], lf[105], rt[105];
int h[205], hsize = 0;
int dp[205][205], root[205][205];

void up(int i) {
  int pidx = i, idx = i >> 1, x = h[i];
  while (idx > 0 &&
         (arr[h[idx]] > arr[h[pidx]] ||
          (arr[h[pidx]] == arr[h[idx]] && arr[lf[h[pidx]]] * arr[rt[h[pidx]]] > arr[lf[h[idx]]] * arr[rt[h[idx]]]))) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx >>= 1;
  }
}

void down(int i) {
  int pidx = i, idx = arr[h[pidx * 2]] > arr[h[pidx * 2 + 1]] ? pidx * 2 + 1 : pidx * 2, x = h[i];
  while (idx <= hsize &&
         (arr[h[pidx]] > arr[h[idx]] ||
          (arr[h[pidx]] == arr[h[idx]] && arr[lf[h[pidx]]] * arr[rt[h[pidx]]] < arr[lf[h[idx]]] * arr[rt[h[idx]]]))) {
    h[pidx] = h[idx];
    h[idx] = x;
    pidx = idx;
    idx = arr[h[idx * 2]] > arr[h[idx * 2 + 1]] ? idx * 2 + 1 : idx * 2;
  }
}

void push(int x) {
  h[++hsize] = x;
  up(hsize);
}

int pop() {
  int res = h[1];
  h[1] = h[hsize--];
  down(1);
  return res;
}

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    lf[i] = i - 1;
    if (lf[i] < 0) lf[i] = n - 1;
    rt[i] = (i + 1) % n;
  }
  for (int i = 0; i < n; ++i) push(i);
}

void init2() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
    arr[i + n] = arr[i];
  }
}

void printOrder(int s, int e) {
  if (e - s < 2)return;
  printOrder(s, root[s][e]);
  printOrder(root[s][e], e);
  cout<<root[s][e]<<endl;
}

void solve2() {
  for (int w = 2; w <= n; ++w) {
    for (int i = 0; i < 2 * n - w; ++i) {
      for (int j = i + 1; j < i + w; ++j) {
        int tmp = dp[i][j] + dp[j][i + w] + arr[i] * arr[j] * arr[i + w];
        if (dp[i][i + w] < tmp) {
          dp[i][i + w] = tmp;
          root[i][i + w] = j;
        }
      }
    }
  }
  int res = 0, s;
  for (int i = 0; i < n; ++i) {
    if (dp[i][i + n] > res) {
      res = dp[i][i + n];
      s = i;
    }
  }
  printf("%d", res);
  //printOrder(s, s+n);
}

// Greedy method no good.
// Counterexample: 13, 8, 7, 10
void solve() {
  int total = 0;
  while (hsize > 1) {
    int ix = pop();
    total += (arr[lf[ix]] * arr[ix] * arr[rt[ix]]);
    int lb = rt[lf[ix]];
    rt[lf[ix]] = rt[ix];
    int la = rt[lf[ix]];
    for (int i = 1; i <= hsize; ++i) {
      if (h[i] == lf[ix]) {
        if (arr[lb] < arr[la]) up(i);
        else down(i);
        break;
      }
    }
    int rb = lf[rt[ix]];
    lf[rt[ix]] = lf[ix];
    int ra = lf[rt[ix]];
    for (int i = 1; i <= hsize; ++i) {
      if (h[i] == rt[ix]) {
        if (arr[rb] < arr[ra]) up(i);
        else down(i);
        break;
      }
    }
  }
  printf("%d", total);
}

int main(){
  init2();
  solve2();
  return 0;
}
