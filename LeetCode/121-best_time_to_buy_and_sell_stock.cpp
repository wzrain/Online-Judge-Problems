class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, mn = INT_MAX;
        for (int i = 0; i < prices.size(); ++i) {
            if (prices[i] < mn) {
                mn = prices[i];
            }
            else {
                res = max(res, prices[i] - mn);
            }
        }
        return res;
    }
};