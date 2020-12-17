// operation 2 means finding a swappable "frequency" array
class Solution {
public:
    bool closeStrings(string word1, string word2) {
        vector<int> c1(26, 0), c2(26, 0);
        for (char &c : word1) {
            c1[c - 'a']++;
        }
        for (char &c : word2) {
            c2[c - 'a']++;
        }
        // need to make sure that no character of frequency 0 is involved in swapping
        for (int i = 0; i < 26; ++i) {
            if ((!min(c1[i], c2[i])) && max(c1[i], c2[i])) return false;
        }
        sort(c1.begin(), c1.end());
        sort(c2.begin(), c2.end());
        return c1 == c2;
    }
};