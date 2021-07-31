class Solution {
public:
    int atoi(string& s) {
        int res = 0;
        for (auto c : s) {
            res += (c - '0');
        }
        return res;
    }
    string itos(int idx) {
        string res;
        while (idx) {
            char s = ((idx % 10) + '0');
            res = s + res;
            idx /= 10;
        }
        return res;
    }
    int getLucky(string s, int k) {
        string news;
        for (auto c : s) {
            int idx = (c - 'a') + 1;
            news += itos(idx);
        }
        while (--k) {
            news = itos(atoi(news));
        }
        return atoi(news);
    }
};