// The idea is to use a map to store the turning points of the top line.
// When a new square comes, traverse the covered turning point to find
// a max height and remove them from the map, and add the new square's
// start index (and end index if necessary) to the map.
// Note that when deleting entries from a map, we can save the key for 
// later deletion, which is probably even better, since the to-be-removed
// keys might also have some other uses before we remove them.
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int n = positions.size();
        vector<int> res;
        int cur = 0;
        // <index of the turning point, height after the turning point>
        map<int, int> height;
        height[0] = 0;
        for (int i = 0; i < n; ++i) {
            int idx = positions[i][0], h = positions[i][1];
            auto iter = prev(height.upper_bound(idx)), del = height.upper_bound(idx);
            int mx = 0;
            // vector<int> old;
            while(iter != height.end() && iter->first < idx + h) {
                mx = max(mx, iter->second);
                iter++;
                // if (iter != height.end() && iter->first < idx + h) old.push_back(iter->first);
            }
            mx += h;
            if (iter == height.end() || iter->first > idx + h) {
                int nh = (prev(iter))->second;
                height[idx + h] = nh;
            }
            // for (int od : old) height.erase(od);
            while (del != height.end() && del->first < idx + h) height.erase(del++);
            height[idx] = mx;
            cur = max(cur, mx);
            res.push_back(cur);
        }
        return res;
    }
};