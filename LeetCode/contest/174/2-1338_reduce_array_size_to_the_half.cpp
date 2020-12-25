class Solution {
public:
    int minSetSize(vector<int>& arr) {
        int sz = arr.size();
        unordered_map<int, int> mp;
        map<int, int> cnts;

        // frequency for each distinct element
        for (int i = 0; i < sz; ++i) {
            mp[arr[i]]++;
        }

        // for each frequency, how many elements are there
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            cnts[it->second]++;
        }
        int res = 0, rem = sz, tgt = sz / 2;
        for (auto it = cnts.rbegin(); it != cnts.rend(); ++it) {
            int curcnt = it->first, num = it->second;
            int tot = curcnt * num;
            if (rem - tot > tgt) {
                res += num;
                rem -= tot;
            }
            else {
                // a subset of the elements of the current frequency will help reach the target
                res += (((rem - tgt) / curcnt) + (((rem - tgt) % curcnt) ? 1 : 0));
                break;
            }
        }
        return res;
    }
};