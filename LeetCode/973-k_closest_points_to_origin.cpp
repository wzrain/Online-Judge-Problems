// O(nlogn) priority queue solution
class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        vector<vector<int>> res;
        int n = points.size();
        auto cmp = [](const pair<int, int>& p1, const pair<int, int>& p2) {
            return p1.first * p1.first + p1.second * p1.second < p2.first * p2.first + p2.second * p2.second;
        };
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(cmp)> pq(cmp);
        for (int i = 0; i < n; ++i) {
            pq.push(make_pair(points[i][0], points[i][1]));
            if (pq.size() > K) pq.pop();
        }
        while (!pq.empty()) {
            res.push_back({pq.top().first, pq.top().second});
            pq.pop();
        }
        return res;
    }
};