#include <iostream>
#include <stdio.h>
#include <map>

using namespace std;

int n, nums[4][505], cnt = 0;
map<int, int> st;
int hs[4000005];

void init() {
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < 4; ++j) {
      scanf("%d", &nums[j][i]);
    }
  }
}

void solve() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      st[nums[0][i] + nums[1][j]] += 1;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      if (st.find(-(nums[2][i] + nums[3][j])) != st.end())
        cnt += st[-(nums[2][i] + nums[3][j])];
    }
  }
  printf("%d", cnt);
}

void solve2() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      hs[nums[0][i] + nums[1][j] + 2000000]++;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cnt += hs[2000000 - (nums[2][i] + nums[3][j])];
    }
  }
  printf("%d", cnt);
}

int main() {
  init();
  solve2();
  return 0;
}
