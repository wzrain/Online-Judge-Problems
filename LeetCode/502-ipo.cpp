// Use greedy strategy, to find every available project with a capital less than the current
// total capital, and take the one with the most profit, and update the current
// total capital and the available projects. 
class Solution {
public:
    int findMaximizedCapital(int k, int W, vector<int>& Profits, vector<int>& Capital) {
        int n = Profits.size();
        vector<pair<int, int>> vec(n);
        for (int i = 0; i < n; ++i) {
            vec[i] = make_pair(Capital[i], Profits[i]);
        }
        
        sort(vec.begin(), vec.end());
        
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            if (p1.second != p2.second) {
                return p1.second < p2.second;
            }
            return p1.first > p2.first;
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        
        int cap = W, idx = 0, cnt = 0;
        while (idx < n && vec[idx].first <= cap) {
            pq.push(vec[idx++]);
        }
        while (cnt < k && !pq.empty()) {
            cap += pq.top().second;
            pq.pop();
            cnt++;
            while (idx < n && vec[idx].first <= cap) {
                pq.push(vec[idx++]);
            }
        }
        return cap;
    }
};