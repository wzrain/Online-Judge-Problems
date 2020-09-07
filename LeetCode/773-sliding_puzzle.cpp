class Solution {
private:
    vector<int> dir = {-1, 0, 1, 0, -1};
    int btoi(vector<vector<int>>& board) {
        int res = 0;
        for (int i = 0; i < 2; ++i) {
            for (int j = 0; j < 3; ++j) {
                res *= 10;
                res += board[i][j];
            }
        }
        return res;
    }
    void itob(int status, vector<vector<int>>& board, int& r, int& c) {
        for (int i = 1; i >= 0; --i) {
            for (int j = 2; j >= 0; --j) {
                board[i][j] = status % 10;
                status /= 10;
                if (!board[i][j]) {
                    r = i;
                    c = j;
                }
            }
        }
    }
    void nextStatus(int cur, vector<int>& res) {
        vector<vector<int>> curb(2, vector<int>(3, 0));
        int r, c;
        itob(cur, curb, r, c);
        for (int d = 0; d < 4; ++d) {
            int nr = r + dir[d], nc = c + dir[d + 1];
            if (nr < 0 || nr > 1 || nc < 0 || nc > 2) continue;
            swap(curb[r][c], curb[nr][nc]);
            res.push_back(btoi(curb));
            swap(curb[r][c], curb[nr][nc]);
        }
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        int status = btoi(board);
        int tgt = 123450;
        if (status == tgt) return 0;
        queue<int> q;
        q.push(status);
        int stp = 1;
        unordered_set<int> visited;
        visited.insert(status);
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                q.pop();
                vector<int> next;
                nextStatus(cur, next);
                for (int nx : next) {
                    if (nx == tgt) return stp;
                    if (visited.find(nx) != visited.end()) continue;
                    visited.insert(nx);
                    q.push(nx);
                }
            }
            stp++;
        }
        return -1;
    }
};