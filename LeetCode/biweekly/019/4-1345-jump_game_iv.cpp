// Basically for every group of elements with the same value v, we use one of the indices as a sentinel to 
// indicate this group is about to be visited (idxes[v].first == 1) in order to reduce the number of searching. 
// In most cases this works because if a search runs into a element with value v and idxes[v].first == 1 that 
// is set in the previous step, that means for this step this element will be visited anyway. However, if idxes[v]
// .first is set as 1 in the current step (which means there are several elements sharing that value in this 
// step), there could be a problem since some elements can reach the final index quicker (for example the final 
// element has exactly the value v, but it will not be put into the queue until next step) by just visiting the 
// element after it iteratively. Therefore when checking elements with the same value, we need to start from the 
// one with the largest index because it has a chance to shorten the search path.
class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int, pair<int, vector<int>>> idxes;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            idxes[arr[i]].first = 0;
            idxes[arr[i]].second.push_back(i);
        }
        vector<int> visited(n, 0);
        queue<int> q;
        q.push(0);
        idxes[arr[0]].first = 1;
        int step = 0;
        while (!q.empty()) {
            int sz = q.size();
            while (sz--) {
                int cur = q.front();
                q.pop();
                if (cur == n - 1) return step;
                if (cur > 0 && !idxes[arr[cur - 1]].first) {
                    idxes[arr[cur - 1]].first = 1;
                    q.push(cur - 1);
                }
                if (!idxes[arr[cur + 1]].first) {
                    idxes[arr[cur + 1]].first = 1;
                    q.push(cur + 1);
                }
                if (idxes[arr[cur]].first == 2) continue;
                int isz = idxes[arr[cur]].second.size();
                // iterate from back to front
                for (int i = isz - 1; i >= 0; --i) {
                    int nx = idxes[arr[cur]].second[i];
                    if (nx == cur) continue;
                    q.push(nx);
                }
                idxes[arr[cur]].first = 2;
            }
            step++;
        }
        return step;
    }
};