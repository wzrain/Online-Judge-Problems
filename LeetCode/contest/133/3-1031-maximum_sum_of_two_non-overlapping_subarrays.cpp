// O(n^2) time with O(n) space
class Solution {
public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    vector<int> ls, ms;
    int lt = 0, mt = 0;
    for (int i = 0; i < L; ++i) {
      lt += A[i];
    }
    for (int i = 0; i < M; ++i) {
      mt += A[i];
    }
    ls.push_back(lt);
    ms.push_back(mt);
    for (int i = 1; i <= A.size() - L; ++i) {
      ls.push_back(ls.back() - A[i - 1] + A[i + L - 1]);
    }
    for (int i = 1; i <= A.size() - M; ++i) {
      ms.push_back(ms.back() - A[i - 1] + A[i + M - 1]);
    }
    int res = 0;
    for (int i = 0; i < ls.size(); ++i) {
      for (int j = 0; j < ms.size(); ++j) {
        if (i == j || (j < i && j + M > i) || (i < j && i + L > j)) continue;
        res = max(res, ls[i] + ms[j]);
      }
    }
    return res;
  }
};

// O(n) time with O(n) space
// For a certain M subarray window, instead of brutely calculate every L window that
// is not overlapped, we can record the max value of these windows during the window
// sum calculation process. So the complexity is reduced by changing "every" from "max".
// Use two vectors to record the largest sum of subarrays with the length of L 
// at the left and right respectively of a certain index.
// So when the M subarray window glide through, it's easy to find the largest L subarray
// without overlapping from these two vectors by the left and right index of the M window.
class Solution {
public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    vector<int> ml, mr;
    int lt = 0, rt = 0;
    for (int i = 0; i < L; ++i) {
      ml.push_back(0);
      lt += A[i];
    }
    ml.push_back(lt);
    int mx = lt;
    for (int i = 1; i <= A.size() - L; ++i) {
      lt = lt - A[i - 1] + A[i + L - 1];
      mx = max(lt, mx);
      ml.push_back(mx);
    }
    for (int i = A.size() - 1; i >= A.size() - L; --i) {
      mr.push_back(0);
      rt += A[i];
    }
    mr.push_back(rt);
    mx = rt;
    for (int i = A.size() - L - 1; i >= 0; --i) {
      rt = rt + A[i] - A[i + L];
      mx = max(rt, mx);
      mr.push_back(mx);
    }
    mr.pop_back(); // The last value means the largest L subarray of the whole array.
                   // It will mess the index after reversing. So pop it.
    reverse(mr.begin(), mr.end());
    
    int tmp = 0;
    for (int i = 0; i < M; ++i) {
      tmp += A[i];
    }
    int res = tmp + mr[M - 1];
    for (int i = 1; i <= A.size() - M; ++i) {
      tmp = tmp - A[i - 1] + A[i + M - 1];
      res = max(res, tmp + max(ml[i], mr[i + M - 1]));
    }
    
    return res;
  }
};

// O(n) time with O(1) space
// There's no need to record every max value, because when an M subarray window gliding,
// the max L subarray before the window could be updated at the same time, which is actually
// merging the loops in the previous solution.
// To find the max value where M window is before the L window, instead of record the max
// L window after each index like the previous solution, just calculate the max M window
// before L window. This is a similar process for finding the max L window before M window.
// And instead of messing with some 0s in the previous solution, just start the calculation
// at the index L + M.
class Solution {
public:
  int maxSumTwoNoOverlap(vector<int>& A, int L, int M) {
    int lmax = 0, mmax = 0, res = 0;
    for (int i = 0; i < L + M; ++i) {
      if (i < L) lmax += A[i];
      if (i < M) mmax += A[i];
      res += A[i];
    }
    int lx = lmax, mx = mmax, lt = res - mmax, mt = res - lmax;
    for (int i = L + M; i < A.size(); ++i) {
      lx = lx + A[i - M] - A[i - L - M];
      mx = mx + A[i - L] - A[i - L - M];
      lt = lt + A[i] - A[i - L];
      mt = mt + A[i] - A[i - M];
      lmax = max(lmax, lx);
      mmax = max(mmax, mx);
      res = max(res, max(lmax + mt, mmax + lt));
    }
    return res;
  }
};