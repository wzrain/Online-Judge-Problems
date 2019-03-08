#include <iostream>
#include <stdio.h>
#include <cstring>

using namespace std;

char text[105][2005];
char ins_str[105];
int line_num = 0;

void print(int n1, int n2) {
    if (n1 <= 0 || n2 <= 0 || n1 > line_num || n2 > line_num || n1 > n2) {
        printf("%s\n", "Error!");
        return;
    }
    for (int i = n1 - 1; i < n2; ++i) {
        printf("%s\n", text[i]);
    }
}

void ins(int i, int j, char* str) {
    if (i <= 0 || i > line_num || j <= 0 || j > strlen(text[i - 1]) + 1) {
        printf("%s\n", "Error!");
        return;
    }
    int len = strlen(text[i - 1]), to_ins_len = strlen(str);
    for (int idx = (len + to_ins_len); idx >= j + to_ins_len - 1; --idx) {
        text[i - 1][idx] = text[i - 1][idx - to_ins_len];
    }
    for (int idx = j - 1; idx < j - 1 + to_ins_len; ++idx) {
        text[i - 1][idx] = str[idx -j + 1];
    }
}

void del(int i, int j, int num) {
    if (i <= 0 || i > line_num || j <= 0 || j > strlen(text[i - 1]) || j + num > strlen(text[i - 1]) + 1) {
        printf("%s\n", "Error!");
        return;
    }
    int prev_len = strlen(text[i - 1]);
    for (int idx = j + num - 1; idx <= prev_len; ++idx) {
        text[i - 1][idx - num] = text[i - 1][idx];
    }
}

void quit() {
    for (int i = 0; i < line_num; ++i) {
        printf("%s\n", text[i]);
    }
}

int main() {
    for (int i = 0; i <= 100; i++) {
        cin.getline(text[i], 2005);
        if (!strcmp(text[i], "******")) {
            line_num = i;
            break;
        }
    }
    while (1) {
        char instruction[10];
        scanf("%s", instruction);
        int i, j, num;
        if (instruction[0] == 'l') {
            scanf("%d%d", &i, &j);
            print(i, j);
        }
        else if (instruction[0] == 'i') {
            scanf("%d%d", &i, &j);
            cin.get();
            cin.getline(ins_str, 105);
            ins(i, j, ins_str);
        }
        else if (instruction[0] == 'd') {
            scanf("%d%d%d", &i, &j, &num);
            del(i, j, num);
        }
        else if (instruction[0] == 'q') {
            quit();
            break;
        }
        else{
            printf("%s\n", "Error!");
        }
    }
    return 0;
}
