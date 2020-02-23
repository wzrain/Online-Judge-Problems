class Solution {
public:
    int consecutiveNumbersSum(int N) {
        int cap = sqrt(2 * N), cnt = 0;
        for (int i = 1; i <= cap; ++i) {
            if (i & 1) {
                if (N % i == 0) cnt++;
            }
            else {
                if (N % i == (i / 2)) cnt++;
            }
        }
        return cnt;
    }
};