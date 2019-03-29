class Solution {
public:
  vector<vector<int>> transpose(vector<vector<int>>& A) {
    if (A.empty()) return A;
    vector<vector<int>> res;//(A[0].size(), vector<int>(A.size(), 0));
    for (int j = 0; j < A[0].size(); ++j) {
      vector<int> tmp;
      for (int i = 0; i < A.size(); ++i) {
         //res[j][i] = A[i][j];
        tmp.push_back(A[i][j]);
      }
      res.push_back(tmp);
    }  
    return res;
  }
};