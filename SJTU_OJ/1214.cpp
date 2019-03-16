#include <iostream>
#include <stdio.h>

using namespace std;

int n, l[100005], rb[100005], v[100005], f[100005], root;
int q[1000005], head = 0, rear = 0;
int stk[1000005], top = 0;

void init() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d%d", &l[i], &rb[i], &v[i]);
    if (l[i]) f[l[i]] = 1;
    if (rb[i]) f[rb[i]] = 1;
  }
  for (int i = 1; i <= n; ++i) {
    if (!f[i]) {
      root = i;
      break;
    }
  }
  q[rear++] = root;
}

void preorder(int rt) {
  if (!rt) return;
  printf("%d ", v[rt]);
  int cr = l[rt];
  while (cr) {
    preorder(cr);
    cr = rb[cr];
  }
}

void postorder(int rt) {
  if (!rt) return;
  int cr = l[rt];
  while (cr) {
    postorder(cr);
    cr = rb[cr];
  }
  printf("%d ", v[rt]);
}

void preorderNonRecur() {
  stk[top++] = root;
  while (top > 0) {
    int tn = stk[top - 1];
    printf("%d ", v[tn]);
    while (l[tn]) {
      stk[top++] = l[tn];
      printf("%d ", v[l[tn]]);
      tn = l[tn];
    }
    tn = stk[--top];
    while (top > 0 && !rb[tn]) tn = stk[--top];
    if (rb[tn]) stk[top++] = rb[tn];
  }
}

void postorderNonRecur() {
  stk[top++] = root;
  while (top > 0) {
    int tn = stk[top - 1];
    while (l[tn]) {
      stk[top++] = l[tn];
      tn = l[tn];
    }
    tn = stk[--top];
    printf("%d ", v[tn]);
    while (top > 0 && !rb[tn]) {
      tn = stk[--top];
      printf("%d ", v[tn]);
    }
    if (rb[tn]) stk[top++] = rb[tn];
  }
}

void levelorder() {
  while (head != rear) {
    printf("%d ", v[q[head]]);
    int lc = l[q[head]];
    while (lc) {
      q[rear++] = lc;
      lc = rb[lc];
    }
    head++;
  }
}

void solve() {
  //preorder(root);
  preorderNonRecur();
  printf("%c", '\n');
  //postorder(root);
  postorderNonRecur();
  printf("%c", '\n');
  levelorder();
}

int main() {
  init();
  solve();
  return 0;
}
