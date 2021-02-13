// when the current comparing characters are the same, find the one with a larger subsequent string by directly 
// comparing the to-be-compared substrings
class Solution {
public:
    string largestMerge(string word1, string word2) {
        string res;
        int l1 = word1.length(), l2 = word2.length(), i = 0, j = 0;
        while (i < l1 && j < l2) {
            if (word1[i] > word2[j]) {
                res += word1[i++];
            }
            else if (word1[i] < word2[j]) {
                res += word2[j++];
            }
            else {
                if (word1.substr(i) > word2.substr(j)) {
                    res += word1[i++];
                }
                else {
                    res += word2[j++];
                }
            }
        }
        while (i < l1) {
            res += word1[i++];
        }
        while (j < l2) {
            res += word2[j++];
        }
        return res;
    }
};