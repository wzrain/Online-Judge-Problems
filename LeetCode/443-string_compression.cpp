class Solution {
public:
    void stoi(string& res, int n) {
        // here creating an extra string might give an extra o(logn) space
        while (n) {
            int cur = n % 10;
            res = (char)(cur + '0') + res;
            n /= 10;
        }
    }
    void add(vector<char>& chars, int& cur, char c) {
        if (cur >= chars.size()) chars.push_back(c);
        else chars[cur] = c;
        cur++;
    }
    int compress(vector<char>& chars) {
        int len = chars.size();
        int i = 0, j = 1, cur = 0;
        while (i < len) {
            while (j < len && chars[j] == chars[i]) j++;
            add(chars, cur, chars[i]);
            if (j - i > 1) {
                string res;
                stoi(res, j - i);
                for (char c : res) {
                    add(chars, cur, c);
                }
            }
            i = j++;
        }
        return cur;
    }
};