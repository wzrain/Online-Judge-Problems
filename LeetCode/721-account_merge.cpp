class Solution {
public:    
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        vector<int> parent(n, 0);
        for (int i = 0; i < n; ++i) {
            parent[i] = i;
        }
        map<string, int> mp;
        for (int i = 0; i < n; ++i) {
            int sz = accounts[i].size();
            for (int j = 1; j < sz; ++j) {
                if (mp.find(accounts[i][j]) == mp.end()) {
                    mp[accounts[i][j]] = i;
                }
                else {
                    Union(i, mp[accounts[i][j]], parent);
                }
            }
        }
        vector<int> idx(n, -1);
        vector<vector<string>> res;
        for (auto iter = mp.begin(); iter != mp.end(); ++iter) {
            int p = Find(iter->second, parent);
            if (idx[p] == -1) {
                idx[p] = res.size();
                res.push_back({accounts[p][0]});
                res.back().push_back(iter->first);
            }
            else {
                res[idx[p]].push_back(iter->first);
            }
        }
        return res;
    }
private:
    int Find(int x, vector<int>& parent) {
        int res = parent[x];
        while (res != parent[res]) res = parent[res];
        while (x != res) {
            int tmp = parent[x];
            parent[x] = res;
            x = tmp;
        }
        return res;
    } 
    void Union(int x, int y, vector<int>& parent) {
        int px = Find(x, parent), py = Find(y, parent);
        if (px != py) {
            parent[px] = py;
        }
    }
};