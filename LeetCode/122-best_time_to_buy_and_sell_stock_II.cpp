class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, n = prices.size(), start = 0, end = 0;
        if (!n) return 0;
        for (int i = 1; i < n; ++i) {
            if (prices[i] > prices[end]) end = i;
            else {
                res += prices[end] - prices[start];
                start = end = i;
            }
        }
        res += prices[end] - prices[start];
        return res;
    }
};