// Randomly generate a index of the white list. Then do 
// binary search on the solution space to find the corresponding
// value. We need to get the current white list index by
// searching the current value in the black list and subtract
// the black list index.
class Solution {
private:
    int total, white;
    vector<int> black;
    int searchInBlack(int tgt) {
        int l = 0, r = black.size();
        while (l < r) {
            int mid = (l + r) / 2;
            if (black[mid] < tgt) l = mid + 1;
            else r = mid;
        }
        return l;
    }
    int searchWhite(int idx) {
        int l = 0, r = total - 1;
        while (l < r) {
            int mid = (l + r) / 2;
            int ix = searchInBlack(mid);
            // cnt indicates how many white values in [0, mid]
            int cnt = mid - ix;
            // not include the current value (mid)
            if (ix < black.size() && mid == black[ix]) cnt--;     
            if (cnt >= idx) r = mid;
            else l = mid + 1;
        }
        return l;
    }
public:
    Solution(int N, vector<int>& blacklist) {
        total = N;
        black = blacklist;
        sort(black.begin(), black.end());
        white = total - black.size();
        srand((unsigned)time(NULL));
    }
    
    int pick() {
        int idx = rand() % white;
        return searchWhite(idx);
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(N, blacklist);
 * int param_1 = obj->pick();
 */