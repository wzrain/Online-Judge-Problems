class Solution {
public:
    int numberOfSteps (int num) {
        int cnt = 0;
        while (num) {
            if (num & 1) {
                num--;
            }
            else num >>= 1;
            cnt++;
        }
        return cnt;
    }
};

class Solution {
public:
    int numberOfSteps (int num) {
        if (!num) return 0;
        int cnt = 0;
        while (num) {
            if (num & 1) cnt += 2;
            else cnt++;
            num >>= 1;
        }
        return cnt - 1;
    }
};