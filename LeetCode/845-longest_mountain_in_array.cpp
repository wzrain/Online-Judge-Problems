// Check the status of a whole section.
// When the updown status changes, update the result and turning points.
class Solution {
public:
  int longestMountain(vector<int>& A) {
    if (A.empty()) return 0;
    int maxl = 0, curl = 0, i = 0, l = -1, updown = 0;
    while (i + 1 < A.size()) {
      if (A[i] > A[i + 1]) {
        if (updown == 1) curl = i - l;
        if (updown != -1) {
          updown = -1;
          l = i;
        }
      }
      else {
        if (updown == -1 && curl != 0) {
          curl += (i - l + 1);
          maxl = max(curl, maxl);
          curl = 0;
        }
        if (updown != 1) l = i;
        if (A[i] == A[i + 1]) {
          updown = 0;
          curl = 0;
        }
        else updown = 1;
      }
      i++;
    }
    if (updown == -1 && curl != 0) {
      curl += (A.size() - l);
      maxl = max(curl, maxl);
    }
    return maxl;
  }
};

// A character of a mountain is that it cantains both ups and downs,
// and first ups, then downs.
// No need to increase i one by one in the outer loop.
class Solution {
public:
  int longestMountain(vector<int>& A) {
    int i = 1, sz = A.size(), maxl = 0;
    while (i < sz) {
      while (i < sz && A[i - 1] == A[i]) i++;
      int up = 0, down = 0;
      while (i < sz && A[i - 1] < A[i]) { // first ups
        up++;
        i++;
      }
      while (i < sz && A[i - 1] > A[i]) { // then downs
        down++;
        i++;
      }
      if (up > 0 && down > 0) maxl = max(maxl, up + down + 1);
    }
    return maxl;
  }
};