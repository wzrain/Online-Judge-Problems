// We also need to try to minimize the total duration to 
// fit more intervals. But here we need to make sure that
// all intervals could finish within its deadline. 
// We accommodate the intervals with earlier deadlines 
// first. The idea is that for a certain deadline we put 
// as many intervals in there and keep minimizing the 
// total duration. So for a interval that cannot fit into
// the current schedule, we just remove the longest 
// current interval after put that one in. So that now we
// we must be able fit the current deadline because an
// interval not shorter than the current one is removed.
// This also minimize the total duration.
class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        int n = courses.size();
        vector<pair<int, int>> ddl_dur(n);
        for (int i = 0; i < n; ++i) {
            ddl_dur[i] = make_pair(courses[i][1], courses[i][0]);
        }
        sort(ddl_dur.begin(), ddl_dur.end());
        priority_queue<int> pq;
        int cur = 0;
        for (int i = 0; i < n; ++i) {
            int ddl = ddl_dur[i].first, dur = ddl_dur[i].second;
            pq.push(dur);
            cur += dur;
            if (cur > ddl) {
                cur -= pq.top();
                pq.pop();
            }
        }
        
        return pq.size();
    }
};