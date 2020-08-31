class Solution {
public:
    vector<int> movesToStamp(string stamp, string target) {
        vector<int> res;
        int star = 0;
        while (replaced(stamp, target, res, star));
        if (star < target.length()) return {};
        reverse(res.begin(), res.end());
        return res;
    }
    bool replaced(string& stamp, string& target, vector<int>& res, int& star) {
        int sl = stamp.length(), tl = target.length();
        if (sl > tl) return false;
        bool cont = false;
        for (int i = 0; i <= tl - sl; ++i) {
            bool rpl = false;
            int si = i, j = 0;
            while (j < sl && (stamp[j] == target[si] || target[si] == '*')) {
                if (target[si] != '*') {
                    rpl = true;
                }
                si++; 
                j++;
            }
            if (j >= sl && rpl) {
                cont = true;
                for (si = i; si < i + sl; ++si) {
                    if (target[si] == '*') continue;
                    star++;
                    target[si] = '*';
                }
                res.push_back(i);
            }
        }
        return cont;
    }
};