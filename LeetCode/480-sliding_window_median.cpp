class Solution {
public:
    struct Node {
        long val;
        Node* prev;
        Node* next;
        Node(long v = 0) : val(v), prev(NULL), next(NULL) {}
    };
    
    void insertAfter(Node* cur, Node* bf) {
        cur->next = bf->next;
        cur->prev = bf;
        if (bf->next) bf->next->prev = cur;
        bf->next = cur;
    }
    void del(Node* cur) {
        cur->prev->next = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
        delete cur;
    }
    
    void addNewVal(map<int, vector<Node*>>& mp, int nw, Node* head) {
        Node* cur = new Node(nw);
        auto it = mp.upper_bound(nw);
        if (it == mp.begin()) {
            insertAfter(cur, head);
        }
        else {
            insertAfter(cur, prev(it)->second.back());
        }
        mp[nw].push_back(cur);
    }
    
    void delOldVal(map<int, vector<Node*>>& mp, int old) {
        del(mp[old].back());
        mp[old].pop_back();
        if (mp[old].empty()) mp.erase(old);
    }
    
    vector<double> medianSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, vector<Node*>> mp;
        vector<double> res;
        Node* head = new Node(0);
        Node* rear = head;
        Node* lf;
        Node* rt;
        for (int i = 0; i < k; ++i) {
            Node* nd = new Node(nums[i]);
            mp[nums[i]].push_back(nd);
        }
        int cnt = 0;
        for (auto it = mp.begin(); it != mp.end(); ++it) {
            for (auto nd : it->second) {
                rear->next = nd;
                nd->prev = rear;
                rear = nd;
                if ((k & 1) && cnt == (k >> 1)) lf = rt = nd;
                else if (!(k & 1)) {
                    if (cnt == (k >> 1) - 1) lf = nd;
                    else if (cnt == (k >> 1)) rt = nd;
                }
                cnt++;
            }
        }
        
        for (int i = k; i < n; ++i) {
            res.push_back((lf->val + rt->val) / 2.0);
            int old = nums[i - k], nw = nums[i];
            if (old == nw) continue;
            if ((old < lf->val && nw < lf->val) || (old > rt->val && nw >= rt->val)) {
                addNewVal(mp, nw, head);
                delOldVal(mp, old);
                continue;
            }
            if (old < lf->val && nw >= rt->val) {
                addNewVal(mp, nw, head);
                delOldVal(mp, old);
                lf = lf->next;
                rt = rt->next;
                continue;
            }
            if (old > rt->val && nw < lf->val) {
                addNewVal(mp, nw, head);
                delOldVal(mp, old);
                lf = lf->prev;
                rt = rt->prev;
                continue;
            }
            if (old <= lf->val && nw >= lf->val && nw < rt->val) {
                addNewVal(mp, nw, head);
                lf = lf->next;
                delOldVal(mp, old);
                continue;
            }
            if (old >= rt->val && nw >= lf->val && nw < rt->val) {
                addNewVal(mp, nw, head);
                rt = rt->prev;
                delOldVal(mp, old);
                continue;
            }
            if (old == lf->val || old == rt->val) {
                if (nw < lf->val) {
                    addNewVal(mp, nw, head);
                    if (mp[old].back() == lf) {
                        if (lf == rt) rt = rt->prev;
                        lf = lf->prev;
                        delOldVal(mp, old);
                    }
                    else {
                        lf = lf->prev;
                        rt = rt->prev;
                        delOldVal(mp, old);
                    }
                }
                else if (nw >= rt->val) {
                    addNewVal(mp, nw, head);
                    if (mp[old].back() == lf) {
                        lf = lf->next;
                        rt = rt->next;
                        delOldVal(mp, old);
                    }
                    else if (mp[old].back() == rt) {
                        if (lf == rt) lf = lf->next;
                        rt = rt->next;
                        delOldVal(mp, old);
                    }
                    else {
                        delOldVal(mp, old);
                    }
                }
                continue;
            }
        }
        res.push_back((lf->val + rt->val) / 2.0);
        return res;
    }
};