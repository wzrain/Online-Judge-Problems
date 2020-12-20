// simulate the process to add up the number of matches
class Solution {
public:
    int numberOfMatches(int n) {
        int cnt = 0;
        while (n > 1) {
            cnt += (n >> 1);
            if (n & 1) n = ((n - 1) >> 1) + 1;
            else n >>= 1;
        }
        return cnt;
    }
};

// since every team need to lose one and only one game 
// except the winner, the total number should be n - 1, period.
class Solution {
public:
    int numberOfMatches(int n) {
        return n - 1;
    }
};