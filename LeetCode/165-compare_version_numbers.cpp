class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i1 = 0, i2 = 0;
        int l1 = version1.length(), l2 = version2.length();
        while (i1 < l1 && i2 < l2) {
            int v1 = 0, v2 = 0;
            while (i1 < l1 && version1[i1] != '.') {
                v1 *= 10;
                v1 += (version1[i1++] - '0');
            }
            i1++;
            while (i2 < l2 && version2[i2] != '.') {
                v2 *= 10;
                v2 += (version2[i2++] - '0');
            }
            i2++;
            if (v1 < v2) return -1;
            if (v1 > v2) return 1;
        }
        while (i1 < l1) {
            int v1 = 0;
            while (i1 < l1 && version1[i1] != '.') {
                v1 *= 10;
                v1 += (version1[i1++] - '0');
            }
            i1++;
            if (v1) return 1;
        }
        while (i2 < l2) {
            int v2 = 0;
            while (i2 < l2 && version2[i2] != '.') {
                v2 *= 10;
                v2 += (version2[i2++] - '0');
            }
            i2++;
            if (v2) return -1;
        }
        return 0;
    }
};