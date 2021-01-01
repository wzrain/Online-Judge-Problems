// The 1's at the start can be leave as-is. For 0's We need to convert them to 1's as advanced as possible, and 
// the method to convert the first-occurred 0 is to form a 00 pattern and convert it to 10. The 10 -> 01 pattern 
// essentially push the 1's to the back, so when a 0 occurs, if the next digit is still 0, it can be directly 
// converted to 1, and if the next digit is 1, then if there are still zeros to come, this 1 can be pushed back 
// and those zeros will be moved front so that pattern 00 can be formed and the current 0 can be converted to 
// 1. If there is no zero to come, then the string cannot be further updated with those two patterns. This 
// forms an optimal solution to convert the 0's at the front to 1's as many as possible.
class Solution {
public:
    string maximumBinaryString(string binary) {
        int len = binary.length(), idx = 0;
        string res, suf;
        while (idx < len && binary[idx] == '1') {
            res += binary[idx++];
        }
        if (idx == len) return res;
        for (; idx < len; ++idx) {
            if (binary[idx] == '1') {
                suf += '1';
            }
        }
        // number of 1's converted from 00 -> 10 pattern (there will be only one 0 left)
        int converted = len - 1 - suf.length() - res.length();
        while (converted--) res += '1';
        return res + '0' + suf;
    }
};