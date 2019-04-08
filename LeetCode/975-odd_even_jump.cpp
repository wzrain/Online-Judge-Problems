class Solution {
public:
  int oddEvenJumps(vector<int>& A) {
    if (A.empty()) return 0;
    int sz = A.size();
    vector<int> can(sz, INT_MIN + 1);
    map<int, int> val_idx;
    val_idx[A.back()] = sz - 1;
    can.back() = 0;
    int res = 1;
    for (int i = sz - 2; i >= 0; --i) {
      if (val_idx.find(A[i]) != val_idx.end()) {
        can[i] = -can[val_idx[A[i]]];
        val_idx[A[i]] = i;
      }
      else {
        val_idx[A[i]] = i;
        auto iter = val_idx.lower_bound(A[i]);
        if (iter != val_idx.begin()) {
          int l = prev(iter)->second;
          if (can[l] == 0 || can[l] == 1) can[i] = -1;
        }
        iter++;
        if (iter != val_idx.end()){
          int r = iter->second;
          if (can[r] == 0 || can[r] == -1) {
            if (can[i] == -1) can[i] = 0;
            else can[i] = 1;
          }
        }
      }
      if (can[i] == 0 || can[i] == 1) res++;
    }
    return res;
  }
};