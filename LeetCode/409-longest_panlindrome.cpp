class Solution {
public:
    int longestPalindrome(string s) {
        // unordered_map<char, int> cnt;
        unordered_set<char> st;
        for (char c : s) {
            // cnt[c]++;
            if (st.find(c) == st.end()) st.insert(c);
            else st.erase(c);
        }
        return s.length() - (st.size() <= 1 ? 0 : (st.size() - 1));
        // int len = 0, odd = 0;
        // for (auto it = cnt.begin(); it != cnt.end(); ++it) {
        //     if (it->second & 1) {
        //         odd = 1;
        //         it->second--;
        //     }
        //     len += it->second;
        // }
        // if (odd) len++;
        // return len;
    }
};