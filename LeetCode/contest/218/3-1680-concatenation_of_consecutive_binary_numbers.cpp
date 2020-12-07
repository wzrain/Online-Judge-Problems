class Solution {
public:
    int concatenatedBinary(int n) {
        // for tracing the current pow(2), can be optimized
        // as one single num
        vector<long> marks(1, 1); 
        while (marks.back() <= n) marks.push_back(marks.back() * 2);
        long base = 1; // record the added binary size
        long res = 0; // need to long here!
        int mod = 1000000007;
        int idx = marks.size() - 2;
        for (long i = n; i > 0; --i) {
            if (i < marks[idx]) idx--;
            res += ((i * base) % mod) % mod;
            base = (base * marks[idx + 1]) % mod;
        }
        while (res < 0) res += mod;
        return res % mod;
    }
};