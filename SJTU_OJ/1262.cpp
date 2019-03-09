#include <iostream>
#include <stdio.h>

using namespace std;

struct info {
  int moment;
  int io;
};

info ms[10005];

void quicksort(info arr[], int l, int r) {
  if (l >= r) return;
  int h = l, e = r;
  info key = arr[h];
  while (h < e) {
    while (h < e &&
           (arr[e].moment > key.moment ||
            (arr[e].moment == key.moment && arr[e].io >= key.io))) --e;
    arr[h] = arr[e];
    while (h < e &&
           (arr[h].moment < key.moment ||
            (arr[h].moment == key.moment && arr[h].io <= key.io))) ++h;
    arr[e] = arr[h];
  }
  arr[h] = key;
  quicksort(arr, l, h - 1);
  quicksort(arr, h + 1, r);
}

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < 2 * n; i = i + 2) {
    int em, lm;
    scanf("%d%d", &em, &lm);
    ms[i].moment = em;
    ms[i].io = 0;
    ms[i + 1].moment = lm;
    ms[i + 1].io = 1;
  }
  quicksort(ms, 0, 2 * n - 1);
  int sm = ms[0].moment, in_stop = 1, fm;
  int stop = 0, no_stop = 0;
  for (int i = 1; i < 2 * n; ++i) {
    if (ms[i].io == 1) {
      in_stop--;
      if (in_stop == 0) {
        fm = ms[i].moment;
        if (fm - sm > stop){
          stop = fm - sm;
        }
      }
    }
    else {
      if (in_stop == 0){
        sm = ms[i].moment;
        if (sm - fm > no_stop) {
          no_stop = sm - fm;
        }
      }
      in_stop++;
    }
  }
  printf("%d %d", stop, no_stop);
}
