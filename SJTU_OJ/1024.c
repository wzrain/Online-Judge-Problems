#include <stdio.h>

int n, arr[10005], tmp[10005];

void init() {
    scanf("%d", &n);
    int i;
    for (i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }
}

void Merge(int l, int mid, int r) {
    int cur = l, pl = l, pr = mid + 1;
    while (pl <= mid && pr <= r) {
        if (arr[pl] < arr[pr]) {
            tmp[cur++] = arr[pl++];
        }
        else tmp[cur++] = arr[pr++];
    }
    while (pl <= mid) {
        tmp[cur++] = arr[pl++];
    }
    while (pr <= r) {
        tmp[cur++] = arr[pr++];
    }
    int i;
    for (i = l; i <= r; ++i) {
        arr[i] = tmp[i];
    }
}

void MergeSort(int l, int r) {
    if (l >= r) return;
    int mid = (l + r) / 2;
    MergeSort(l, mid);
    MergeSort(mid + 1, r);
    Merge(l, mid, r);
}

void solve() {
    MergeSort(0, n - 1);
    int i;
    for (i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }
    printf("%s", "\n");
}

int main() {
    init();
    solve();
    return 0;
}