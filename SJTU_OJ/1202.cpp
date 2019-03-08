#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

struct BigInt {
  int bit;
  BigInt* next;
};

char A[1000005], B[1000005], res[1000005];

int main() {
  scanf("%s", A);
  scanf("%s", B);

  BigInt *head1, *head2, *p;
  head1 = new BigInt;
  head2 = new BigInt;
  
  p = head1;
  for (int i = strlen(A) - 1; i >= 0; i--) {
    p->next = new BigInt;
    p->next->bit = A[i] - '0';
    p = p->next;
  }

  p = head2;
  for (int i = strlen(B) - 1; i >= 0; i--) {
    p->next = new BigInt;
    p->next->bit = B[i]-'0';
    p = p->next;
  }

  BigInt *head;
  head = new BigInt;
  
  BigInt *q1 = head1->next;
  BigInt *q2 = head2->next;
  BigInt *q = head;
  int addnum = 0;

  while (q1 != NULL && q2 != NULL) {
    q->next = new BigInt;
    q->next->bit = q1->bit + q2->bit + addnum;
    if (q->next->bit >= 10) {
      addnum = 1;
      q->next->bit -= 10;
    }
    else {
      addnum = 0;
    }
    q = q->next;
    q1 = q1->next;
    q2 = q2->next;
  }

  if (q1 != NULL) {
    q->next = q1;
  }
  if (q2 != NULL) {
    q->next=q2;
  }

  while (addnum && q->next != NULL) {
    q->next->bit += addnum;
    addnum = q->next->bit / 10;
    q->next->bit = q->next->bit % 10;
    q = q->next;
  }
  if (addnum == 1) {
    q->next = new BigInt;
    q->next->bit = 1;
  }

  q = head;
  int len = 0;
  while (q->next != NULL) {
    res[len++] = q->next->bit;
    q = q->next;
  }

  for (int i = len - 1; i >= 0; i--) {
    printf("%d", res[i]);
  }
  return 0;
}
