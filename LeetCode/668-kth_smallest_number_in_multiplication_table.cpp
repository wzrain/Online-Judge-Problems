// For a given number i, the number of numbers smaller than i in the multiplication table is i + i / 2 + i / 3...
// So just binary search the answer.
class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        if (m < n) swap(m, n);
        int l = 1, r = m * n;
        while (l < r) {
            int cnt = 0, mid = (l + r) / 2;
            for (int i = 1; i <= n; ++i) {
                cnt += min((mid / i), m);
            }
            if (cnt >= k) r = mid;
            else l = mid + 1;
        }
        return l;
    }
};