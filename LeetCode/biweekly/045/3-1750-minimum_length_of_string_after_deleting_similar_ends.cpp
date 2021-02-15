class Solution {
public:
    int minimumLength(string s) {
        int len = s.length();
        int i = 0, j = len - 1;
        // The logic should be that i and j all points to the current to-remove element
        // Use i < j in the outer loop to make sure that i and j do not indicate the same value, which cannot be removed
        while (i < j && s[i] == s[j]) {
            char cur = s[i];
            // Use i <= j in the inner loop to make sure everything is removed in situations like "aaa".
            // If using i < j, the last element when i == j is not removed properly
            while (i <= j && s[i] == cur) i++;
            while (i <= j && s[j] == cur) j--;
        }
        return j - i + 1;
    }
};