#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct node {
  int val;
  node* l;
  node* r;
  node(int v = 0) : val(v), l(NULL), r(NULL) {}
};

void ins(node* &rt, int x) {
  if (!rt) {
    rt = new node(x);
    return;
  }
  if (x < rt->val) ins(rt->l, x);
  else ins(rt->r, x);
}

void del(node* &rt, int x) {
  if (!rt) return;
  if (rt->val == x) {
    if (rt->r) {
      node* tmp = rt->r;
      while (tmp->l) {
        tmp = tmp->l;
      }
      rt->val = tmp->val;
      del(rt->r, tmp->val);
    }
    else rt = rt->l;
    return;
  }
  if (x < rt->val) del(rt->l, x);
  else del(rt->r, x);
}

void dlt(node* &rt, int x) {
  if (!rt) return;
  if (rt->val < x) {
    rt = rt->r;
    dlt(rt, x);
  }
  else dlt(rt->l, x);
}

void dgt(node* &rt, int x) {
  if (!rt) return;
  if (rt->val > x) {
    rt = rt->l;
    dgt(rt, x);
  }
  else dgt(rt->r, x);
}

void di(node* &rt, int x, int y) {
  if (!rt) return;
  if (rt->val <= x) di(rt->r, x, y);
  else if (rt->val >= y) di(rt->l, x, y);
  else {
    del(rt, rt->val);
    di(rt, x, y);
  }
}

bool Find(node* rt, int x) {
  if (!rt) return false;
  if (rt->val == x) return true;
  if (x < rt->val) return Find(rt->l, x);
  return Find(rt->r, x);
}

int treesize(node* rt) {
  if (!rt) return 0;
  return treesize(rt->l) + treesize(rt->r) + 1;
}

int fith(node* rt, int i) {
  if (!rt) return -1;
  int lsz = treesize(rt->l);
  if (lsz == i - 1) return rt->val;
  if (lsz < i - 1) return fith(rt->r, i - lsz - 1);
  return fith(rt->l, i);
}

void solve() {
  int n;
  scanf("%d", &n);
  node* root = NULL;
  for (int u = 0; u < n; ++u) {
    char op[50];
    scanf("%s", op);
    int x;
    scanf("%d", &x);
    if (op[0] == 'i') ins(root, x);
    else if (op[0] == 'd') {
      if (strlen(op) < 10) del(root, x);
      else if (op[7] == 'l') dlt(root, x);
      else if (op[7] == 'g') dgt(root, x);
      else if (op[7] == 'i') {
        int y;
        scanf("%d", &y);
        di(root, x, y);
      }
    }
    else if (op[0] == 'f') {
      if (strlen(op) < 5) {
        if (Find(root, x)) printf("%s\n", "Y");
        else printf("%s\n", "N");
      }
      else if (op[5] == 'i') {
        int res = fith(root, x);
        if (res == -1) printf("%s\n", "N");
        else printf("%d\n", res);
      }
    }
  }
}

int main(){
  solve();
  return 0;
}
