class Solution {
public:
    int longestOnes(vector<int>& A, int K) {
        int i = 0, j = 0, cnt = 0, res = 0;
        while (i < A.size() && j < A.size()) {
            if (A[j] == 0) {
                cnt++;
                if (cnt > K) {
                    while (i < A.size() && A[i] == 1) i++;
                    i++;
                    cnt--;
                }
            }
            if (i > j) j = i;
            else j++;
            res = max(j - i, res);
        }
        return res;
    }
};