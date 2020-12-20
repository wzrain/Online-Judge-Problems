// At least the number of the max digit is needed since 
// only 0 or 1 is contained in deci-binary numbers. If 
// we resort to carrying bits, at least 10 numbers are 
// needed, so that's not optimal.
class Solution {
public:
    int minPartitions(string n) {
        int mx = 0;
        for (auto c : n) {
            mx = max(mx, c - '0');
        }
        return mx;
    }
};