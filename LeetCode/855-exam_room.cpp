// O(logn) insert and delete
class ExamRoom {
private:
    int capacity;
    // Use the max distance an interval can provide as the key of the map.
    // The value of the map is a set of indices which could achieve such
    // max distance inside an existing interval.
    map<int, set<int>> mp;
    // Save the corresponding interval of the certain index in the set.
    // If the index is 0 or capacity, the corresponding pair value is infinite.
    // These indices (in mp's value and lr's key) are all non-seated. 
    unordered_map<int, pair<int, int>> lr;
    // Save the left and right indices of a seated indices, which is used
    // when leave() is called. If there's no left or right, the corresponding
    // value is infinite.
    unordered_map<int, pair<int, int>> itv;
public:
    ExamRoom(int N) {
        capacity = N - 1;
        mp[INT_MAX].insert(0);
        lr[0] = make_pair(INT_MIN, INT_MAX);
    }
    
    int seat() {
        int last = mp.rbegin()->first;
        int pos = *(mp[last].begin());
        int l = lr[pos].first, r = lr[pos].second;
        if (l == INT_MIN && r == INT_MAX) {
            mp[INT_MAX].insert(capacity);
            lr[capacity] = make_pair(0, INT_MAX);
        }
        else {
            int lf = l == INT_MIN ? 0 : l, rf = r == INT_MAX ? capacity : r;
            int lx = (lf + pos) / 2, rx = (pos + rf) / 2;
            if (lx > lf) {
                mp[lx - lf].insert(lx);
                lr[lx] = make_pair(lf, pos);
            }
            if (rx > pos) {
                mp[rx - pos].insert(rx);
                lr[rx] = make_pair(pos, r);
            }
        }
        itv[pos] = make_pair(l, r);
        if (l != INT_MIN) itv[l].second = pos;
        if (r != INT_MAX) itv[r].first = pos;
        mp[last].erase(pos);
        if (mp[last].empty()) mp.erase(last);
        lr.erase(pos);
        
        return pos;
    }
    
    void leave(int p) {
        int li = itv[p].first, ri = itv[p].second;
        itv.erase(p);
        if (li != INT_MIN) {
            itv[li].second = ri;
        }
        if (ri != INT_MAX) {
            itv[ri].first = li;
        }
        
        if (li == INT_MIN && ri == INT_MAX) {
            mp.clear();
            lr.clear();
            mp[INT_MAX].insert(0);
            lr[0] = make_pair(INT_MIN, INT_MAX);
        }
        else {
            int lx, rx, ld, rd, np, nd;
            if (li == INT_MIN) {
                lx = 0; rx = (p + ri) / 2;
                ld = p;
                np = 0; nd = ri;
            } 
            else {
                lx = (p + li) / 2;
                rx = ri == INT_MAX ? capacity : (p + ri) / 2;
                ld = lx - li;
                np = ri == INT_MAX ? capacity : (li + ri) / 2;
                nd = np - li;
            }
            rd = rx - p;
            mp[ld].erase(lx);
            if (mp[ld].empty()) mp.erase(ld);
            mp[rd].erase(rx);
            if (mp[rd].empty()) mp.erase(rd);
            if (lx) lr.erase(lx);
            if (rx != capacity) lr.erase(rx);
            mp[nd].insert(np);
            lr[np] = make_pair(li, ri);
        }
    }
};

/**
 * Your ExamRoom object will be instantiated and called as such:
 * ExamRoom* obj = new ExamRoom(N);
 * int param_1 = obj->seat();
 * obj->leave(p);
 */