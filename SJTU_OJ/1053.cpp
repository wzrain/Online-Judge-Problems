#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
  int val;
  int rc;
  node* next;
  node(int v = 0, int r = 0) : val(v), rc(r), next(NULL) {}
};

int n, m;
node* rows[100005];
node* columns[100005];
int rs[100005], cs[100005];

void init() {
  scanf("%d", &n);
  for (int i = 0; i < 100005; ++i) {
    rows[i] = new node;
    columns[i] = new node;
  }

  for (int i = 0; i < n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    node* rp = rows[x];
    while (rp->next) rp = rp->next;
    rp->next = new node(z, y);
    node* cp = columns[y];
    while (cp->next) cp = cp->next;
    cp->next = new node(z, x);
  }
  scanf("%d", &m);
}

void init2() {
  scanf("%d", &n);
  for (int i = 0; i < 100005; ++i) {
    rows[i] = new node;
    rs[i] = i;
    cs[i] = i;
  }
  for (int i = 0; i < n; ++i) {
    int x, y, z;
    scanf("%d%d%d", &x, &y, &z);
    node* rp = rows[x];
    while (rp->next) rp = rp->next;
    rp->next = new node(z, y);
  }
  scanf("%d", &m);
}

void updateRow(int rx, int ry) {
  node* xp = rows[rx];
  while (xp->next) {
    int col = xp->next->rc;
    xp = xp->next;
    node* cp = columns[col];
    if (columns[col]->val == 1) {
      columns[col]->val = 0;
      continue;
    }
    while (cp->next) {
      if (cp->next->rc == rx) {
        cp->next->rc = ry;
      }
      else if (cp->next->rc == ry) {
        cp->next->rc = rx;
        columns[col]->val = 1;
      }
      cp = cp->next;
    }
  }
}

void updateCol(int cx, int cy) {
  node* xp = columns[cx];
  while (xp->next) {
    int r = xp->next->rc;
    xp = xp->next;
    node* rp = rows[r];
    if (rows[r]->val == 1) {
      rows[r]->val = 0;
      continue;
    }
    while (rp->next) {
      if (rp->next->rc == cx) {
        rp->next->rc = cy;
      }
      else if (rp->next->rc == cy) {
        rp->next->rc = cx;
        rows[r]->val = 1;
      }
      rp = rp->next;
    }
  }
}

void rowSwitch(int rx, int ry) {
  updateRow(rx, ry);
  updateRow(ry, rx);
  node* tmp = rows[rx]->next;
  rows[rx]->next = rows[ry]->next;
  rows[ry]->next = tmp;
}

void colSwitch(int cx, int cy) {
  updateCol(cx, cy);
  updateCol(cy, cx);
  node* tmp = columns[cx]->next;
  columns[cx]->next = columns[cy]->next;
  columns[cy]->next = tmp;
}

void query(int r, int c) {
  node* rp = rows[r];
  while (rp->next) {
    if (rp->next->rc == c) {
      printf("%d\n", rp->next->val);
      return;
    }
    rp = rp->next;
  }
  printf("%d\n", 0);
}

// only swap the indices to record the current status
void swc(int x, int y, int op) {
  if (op == 0) {
    int tmp = rs[x];
    rs[x] = rs[y];
    rs[y] = tmp;
  }
  else if (op == 1) {
    int tmp = cs[x];
    cs[x] = cs[y];
    cs[y] = tmp;
  }
}

void solve() {
  for (int u = 0; u < m; ++u) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 0) rowSwitch(x, y);
    else if (op == 1) colSwitch(x, y);
    else if (op == 2) query(x, y);
  }
}

void solve2() {
  for (int u = 0; u < m; ++u) {
    int op, x, y;
    scanf("%d%d%d", &op, &x, &y);
    if (op == 2) query(rs[x], cs[y]);
    else swc(x, y, op);
  }
}

int main() {
  init2();
  solve2();
  return 0;
}
