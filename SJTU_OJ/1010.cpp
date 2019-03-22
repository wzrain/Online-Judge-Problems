#include <iostream>
#include <stdio.h>

using namespace std;

int bud[13];

void init() {
  for (int i = 1; i <= 12; ++i) scanf("%d", &bud[i]);
}

void solve() {
  int inhand = 0, saved = 0;
  for (int i = 1; i <= 12; ++i) {
    inhand += 300;
    if (inhand < bud[i]) {
      printf("%d", -i);
      return;
    }
    saved += 100 * ((inhand - bud[i]) / 100);
    inhand = (inhand - bud[i]) % 100;
  }
  printf("%.f", saved * 1.2 + inhand);
}

int main(){
  init();
  solve();
  return 0;
}
