class Solution {
public:
    string reformatNumber(string number) {
        string num, res;
        for (auto &c : number) {
            if (c >= '0' && c <= '9') num += c;
        }
        int len = num.length();
        int start = 0, block = 3;
        for (int i = 0; i < len; ++i) {
            if ((i - start) % block == 0) {
                if (i) res += '-';
                if (len - i == 4) {
                    start = i;
                    block = 2;
                }
            }
            res += num[i];
        }
        return res;
    }
};