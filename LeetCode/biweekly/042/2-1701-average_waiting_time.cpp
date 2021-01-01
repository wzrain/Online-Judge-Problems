class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& customers) {
        int n = customers.size();
        int cur = 0;
        long wt = 0;
        for (int i = 0; i < n; ++i) {
            if (cur < customers[i][0]) cur = customers[i][0];
            wt += (cur + customers[i][1] - customers[i][0]);
            cur += customers[i][1]; 
        }
        return wt * 1.0 / n;
    }
};