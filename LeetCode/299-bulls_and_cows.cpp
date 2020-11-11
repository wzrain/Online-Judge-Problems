class Solution {
public:
    string getHint(string secret, string guess) {
        string res;
        int len = secret.length();
        int bull = 0, cow = 0;
        vector<int> cnt(10, 0);
        vector<int> sv(10, 0), gv(10, 0);
        for (int i = 0; i < len; ++i) {
            if (secret[i] == guess[i]) {
                bull++;
                cnt[secret[i] - '0']++;
            }
            sv[secret[i] - '0']++;
            gv[guess[i] - '0']++;
        }
        for (int i = 0; i < 10; ++i) {
            cow += (min(sv[i], gv[i]) - cnt[i]);
        }
        res = to_string(bull) + "A" + to_string(cow) + "B";
        return res;
    }
};