// O(nlogk) priority queue solution
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

// Average O(n) solution based on quicksort
class Solution {
public:
    int division(vector<vector<int>>& pts, int low, int high) {
        int first = low, last = high;
        vector<int> key = pts[first];
        while (first < last) {
            while (first < last && key[0] * key[0] + key[1] * key[1] <= pts[last][0] * pts[last][0] + pts[last][1] * pts[last][1]) last--;
            pts[first] = pts[last];
            while (first < last && key[0] * key[0] + key[1] * key[1] >= pts[first][0] * pts[first][0] + pts[first][1] * pts[first][1]) first++;
            pts[last] = pts[first];
        }
        pts[first] = key;
        return first;
    }
    void kth(vector<vector<int>>& pts, int low, int high, int k) {
        int key = division(pts, low, high);
        if (key == k + low - 1) return;
        if (key > k + low - 1) kth(pts, low, key - 1, k);
        else kth(pts, key + 1, high, k - key + low - 1);
        // The implementation could also be:
        /*
         * if (low > high) return; // This is unnecessary if we use key == k - 1 rather than key == k
         * int key = division(pts, low, high);
         * if (key == k) return;
         * if (key > k) kth(pts, low, key - 1, k);
         * else kth(pts, key + 1, high, k);
         */
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {
        kth(points, 0, points.size() - 1, K);
        return vector<vector<int>>(points.begin(), points.begin() + K);
    }
};