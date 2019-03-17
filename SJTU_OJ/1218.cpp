#include <iostream>
#include <stdio.h>

using namespace std;

struct node {
  int val;
  node* next;
  node (int v = -2000000000) : val(v), next(NULL) {}
};

int n, m;

void add(node* head, int v) {
  node* p = head;
  while (p->next != NULL) {
    if (p->next->val == v) return;
    else if (p->next->val > v) {
      node* vn = new node(v);
      vn->next = p->next;
      p->next = vn;
      return;
    }
    p = p->next;
  }
  node* vn = new node(v);
  p->next = vn;
}

void diff(node* head, int v) {
  node* p = head;
  while (p->next != NULL) {
    if (p->next->val == v) {
      p->next = p->next->next;
      break;
    }
    p = p->next;
  }
}

void intersect(node* head, node* nh, int v) {
  node* p = head;
  while (p->next != NULL) {
    if (p->next->val == v) {
      add(nh, v);
      return;
    }
    p = p->next;
  }
}

void print(node* head) {
  node* p = head;
  while (p != NULL) {
    printf("%d ", p->val);
    p = p->next;
  }
  printf("%c", '\n');
}

void solve() {
  node* head = new node;
  scanf("%d", &n);
  for (int iii = 0; iii < n; ++iii) {
    char op[5];
    scanf("%s", op);
    int m; scanf("%d", &m);
    if (op[0] == '+') {
      for (int i = 0; i < m; ++i) {
        int v; scanf("%d", &v);
        add(head, v);
      }
    }
    else if (op[0] == '-') {
      for (int i = 0; i < m; ++i) {
        int v; scanf("%d", &v);
        diff(head, v);
      }
    }
    else if (op[0] == '*') {
      node* nh = new node;
      for (int i = 0; i < m; ++i) {
        int v; scanf("%d", &v);
        intersect(head, nh, v);
      }
      head = nh;
    }
    print(head->next);
  }
}

int main() {
  solve();
  return 0;
}
