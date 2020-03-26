// Find the earliest spot where the original string
// matches the reversed string all the way to the end
// of the reversed one.
class Solution {
public:
    string shortestPalindrome(string s) {
        if (s.empty()) return s;
        string tmpl = s;
        reverse(tmpl.begin(), tmpl.end());
        int slen = s.length();
        vector<int> next(slen);
        next[0] = -1;
        for (int j = 1; j < slen; ++j) {
            int tmp = next[j - 1];
            while (tmp != -1 && s[tmp] != s[j - 1]) tmp = next[tmp];
            next[j] = tmp + 1;
        }
        int pt = 0, ps = 0;
        while (pt < slen) {
            if (tmpl[pt] == s[ps]) {
                pt++;
                ps++;
            }
            else {
                ps = next[ps];
                if (ps == -1) {
                    pt++;
                    ps = 0;
                }
            }
        }
        return tmpl.substr(0, slen - ps) + s;
    }
};