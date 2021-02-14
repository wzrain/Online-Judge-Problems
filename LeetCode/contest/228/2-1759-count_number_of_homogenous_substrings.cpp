class Solution {
public:
    int countHomogenous(string s) {
        long res = 0;
        int cur = 0, len = s.length();
        for (int i = 1; i <= len; ++i) {
            if (i == len || s[i] != s[i - 1]) {
                long num = i - cur;
                cur = i;
                res += (num * (num + 1) / 2);
                res %= (int)(1e9 + 7);
            }
        }
        return res;
    }
};

// we can directly count 1+2+...+n along with the loop, without calculating n(n-1)/2 explicitly
class Solution {
public:
    int countHomogenous(string s) {
        long res = 0;
        int cur = 0, len = s.length(), cnt = 0;
        for (int i = 0; i < len; ++i) {
            if (s[i] != s[cur]) {
                cnt = 0;
                cur = i;
            }
            res += (++cnt);
            res %= (int)(1e9 + 7);
        }
        return res;
    }
};