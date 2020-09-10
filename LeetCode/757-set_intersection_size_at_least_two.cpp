// The idea is inspired by finding the most number of
// non-overlapping intervals, which is solved via a 
// greedy strategy of selecting the intervals with the
// most left ending point. Here we are also dealing with
// some intervals, but finding overlaps. If we save the
// largest two numbers in a overlap, there will be larger
// chances that they are also in the next interval if the
// next interval has a larger starting point as well as a
// larger ending point, which tend to reduce the total
// number of the final result. 
// So the first try is to find intervals with no smaller
// intervals, which means it cannot cover any other 
// intervals. This kind of intervals will form a set where
// between two intervals there will always be one with both
// larger starting point and larger ending point. And we only
// need to record the last two intersection numbers and update
// them according to interval positions.
// However this gives O(n^2) complexity. Actually we only need
// to sort the original intervals by its ending point, since
// only the ending points matter in our calculation, just like
// what we do when finding the most number of non-overlapping
// intervals. We also need to process intervals with larger
// starting point first if they have the same ending point,
// since the shortest interval decides the final result. If we
// process the longer intervals first, we might get f == l, but
// we still regard them as two different points, which leads
// to errors.
class Solution {
public:
    int intersectionSizeTwo(vector<vector<int>>& intervals) {
        int n = intervals.size();
        // vector<bool> hasSmaller(n, false);
        // for (int i = 0; i < n; ++i) {
        //     for (int j = i + 1; j < n; ++j) {
        //         if (intervals[i][0] == intervals[j][0] && 
        //             intervals[i][1] == intervals[j][1]) {
        //             hasSmaller[j] = true;
        //             continue;
        //         }
        //         if (intervals[j][0] <= intervals[i][0] && 
        //             intervals[j][1] >= intervals[i][1]) {
        //             hasSmaller[j] = true;
        //         }
        //         if (intervals[j][0] >= intervals[i][0] && 
        //             intervals[j][1] <= intervals[i][1]) {
        //             hasSmaller[i] = true;
        //         }
        //     }
        // }
        vector<pair<int, int>> itvs;
        for (int i = 0; i < n; ++i) {
            // if (hasSmaller[i]) continue;
            // itvs.push_back(make_pair(intervals[i][0], intervals[i][1]));
            itvs.push_back(make_pair(intervals[i][1], -intervals[i][0]));
        }
        sort(itvs.begin(), itvs.end());
        
        int f = -1, l = -1, cnt = 0;
        for (int i = 0; i < itvs.size(); ++i) {
            // int lf = itvs[i].first, rt = itvs[i].second;
            int lf = -itvs[i].second, rt = itvs[i].first;
            if (lf <= f) continue;
            else if (lf > f && lf <= l) {
                f = l;
                l = rt;
                cnt++;
            }
            else {
                f = rt - 1;
                l = rt;
                cnt += 2;
            }
        }
        return cnt;
    }
};