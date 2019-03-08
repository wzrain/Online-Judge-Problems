#include <iostream>
#include <cstdio>

using namespace std;

int times[100005], people_num;
long long ow[3], nw[3];
int of[3], nf[3];

int max_in_3(int a, int b, int c) {
  if (a >= b && a >= c) {
    return a;
  }
  if (b >= c) {
    return b;
  }
  return c;
}

int min_index_in_3(int a, int b, int c) {
  if (a <= b && a <= c) {
    return 0;
  }
  if (b <= c) {
    return 1;
  }
  return 2;
}

void old_queue() {
  for (int i = 0; i < people_num; ++i) {
    ow[i % 3] += of[i % 3];
    of[i % 3] += times[i];
  }
  long long ow_sum = ow[0] + ow[1] + ow[2];
  int of_max = max_in_3(of[0], of[1], of[2]);
  printf("%lld %d\n", ow_sum, of_max);
}

void new_queue() {
  for (int i = 0; i < people_num; ++i) {
     int idx = min_index_in_3(nf[0], nf[1], nf[2]);
     nw[idx] += nf[idx];
     nf[idx] += times[i];
  }
  long long nw_sum = nw[0] + nw[1] + nw[2];
  int nf_max = max_in_3(nf[0], nf[1], nf[2]);
  printf("%lld %d\n", nw_sum, nf_max);
}

int main() {
  scanf("%d", &people_num);
  for (int i = 0; i < people_num; ++i) {
    scanf("%d", &times[i]);
  }

  old_queue();
  new_queue();

  return 0;
}
