/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
  vector<Interval> merge(vector<Interval>& intervals) {
    if (intervals.empty()) return intervals;
    auto cmp = [](Interval i1, Interval i2) {
      return i1.start < i2.start;
    };
    sort(intervals.begin(), intervals.end(), cmp);
    vector<Interval> res;
    int in = intervals[0].start, out = intervals[0].end;
    for (int i = 1; i < intervals.size(); ++i) {
      if (intervals[i].start > out) {
        res.push_back(Interval(in, out));
        in = intervals[i].start;
        out = intervals[i].end;
        continue;
      }
      if (intervals[i].end > out) out = intervals[i].end;
    }
    res.push_back(Interval(in, out));
    return res;
  }
};