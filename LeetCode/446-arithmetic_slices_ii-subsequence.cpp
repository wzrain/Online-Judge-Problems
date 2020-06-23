// mp[i][diff] indicates the number of arithmetic sequences ending
// at the ith element plus the number of <j, i> pair where A[i] - A[j]
// is diff. So for each <j, i> pair, there will be mp[j][diff] more
// target sequences, and mp[i][diff] will add to mp[j][diff] + the 
// <j, i> pair itself.
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& A) {
        int n = A.size(), cnt = 0;
        vector<unordered_map<long, int>> mp(n);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                long diff = (long)A[i] - (long)A[j];
                if (diff > INT_MAX || diff < INT_MIN) continue;
                if (mp[j].find(diff) == mp[j].end()) {
                    mp[i][diff]++;
                }
                else {
                    mp[i][diff] += mp[j][diff] + 1;
                    cnt += mp[j][diff];
                }
            }
        }
        return cnt;
    }
};