#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char stk[400], str[400];
int top = 0;

bool match() {
  while(scanf("%s", str) != EOF) {
    if (!strcmp(str, "begin")) {
      stk[top++] = 'b';
    }
    else if (!strcmp(str, "if")) {
      stk[top++] = 'i';
    }
    else if (!strcmp(str,"then")) {
      if (top == 0) return false;
      if (stk[top - 1] != 'i') return false;
      stk[top++] = 't';
    }
    else if (!strcmp(str, "end")) {
      while (top > 0 && stk[top - 1] == 't') top -= 2;
      if (top <= 0) return false;
      if (stk[top - 1] != 'b') return false;
      top--;
    }
    else if (!strcmp(str, "else")) {
      if (top == 0) return false;
      if (stk[top - 1] != 't') return false;
      top -= 2;
    }
  }
  if (top) return false;
  return true;
}

int main() {
  bool flag = match();
  if (flag) printf("%s", "Match!");
  else printf("%s", "Error!");
  return 0;
}
