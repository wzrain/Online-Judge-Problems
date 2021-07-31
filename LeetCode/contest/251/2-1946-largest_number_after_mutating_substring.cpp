class Solution {
public:
    string maximumNumber(string num, vector<int>& change) {
        string res = num;
        int len = res.length(), i = 0;
        while (i < len) {
            bool found = false;
            if (change[res[i] - '0'] > res[i] - '0') {
                found = true;
                while (i < len && change[res[i] - '0'] >= res[i] - '0') {
                    res[i] = (change[res[i] - '0']) + '0';
                    i++;
                }
            }
            
            if (found) break;
            i++;
        }
        return res;
    }
};