// The idea is to construct a linked list and save the LFU element
// at the head of the list to make the remove operation O(1). For
// adjustment, we need to find the most recent used element for a
// certain frequency and insert the accessed element after it. 
// So when adding a key (node), we need to insert it after the most
// recent used element of frequency 1 or head. Update of the list
// requires checking whether the node is the most recent used element
// of the previous frequency, and where to insert.
class LFUCache {
private:
    struct Node {
        int key, value;
        Node* prev;
        Node* next;
        Node(int k = 0, int v = 0) : key(k), value(v), prev(NULL), next(NULL) {}
    };
    // <key, <Node*, frequency>>
    unordered_map<int, pair<Node*, int>> mp;
    
    // Save the last node for each frequency.
    unordered_map<int, Node*> vec;
    
    Node* head;
    int cap;
    
    void insertAfter(Node* cur, Node* bf) {
        cur->prev = bf;
        cur->next = bf->next;
        if (bf->next) bf->next->prev = cur;
        bf->next = cur;
    }
    
    void addNode(Node* cur) {
        if (vec[1]) {
            insertAfter(cur, vec[1]);
        }
        else {
            insertAfter(cur, head);
        }
        vec[1] = cur;
    }
    
    void delNode(Node* cur, int idx) {
        if (vec[idx] == cur) {
            Node* cand = cur->prev;
            if (cand && cand != head && mp[cand->key].second == idx) {
                vec[idx] = cand;
            }
            else vec[idx] = NULL;
        }
        cur->prev->next = cur->next;
        if (cur->next) cur->next->prev = cur->prev;
    }
    
    void updateNode(Node* cur, int preidx, Node* bf) {
        delNode(cur, preidx);
        insertAfter(cur, bf);
        vec[preidx + 1] = cur;
    }
    
    void update(Node* cur, int preidx) {
        int curidx = preidx + 1;
        if (!vec[curidx]) {
            if (vec[preidx] == cur) {
                Node* cand = cur->prev;
                if (cand && cand != head && mp[cand->key].second == preidx) {
                    vec[preidx] = cand;
                    updateNode(cur, preidx, cand);
                }
                else {
                    // no need to change the list, just update the frequency
                    vec[preidx] = NULL;
                    vec[curidx] = cur;
                }
            }
            else {
                updateNode(cur, preidx, vec[preidx]);
            }
        }
        else {
            updateNode(cur, preidx, vec[curidx]);
        }
    }
public:
    LFUCache(int capacity) {
        cap = capacity;
        head = new Node(-2, -2);
    }
    
    int get(int key) {
        if (mp.find(key) == mp.end()) return -1;
        Node* cur = mp[key].first;
        int idx = mp[key].second++;
        update(cur, idx);
        return cur->value;
    }
    
    void put(int key, int value) {
        if (!cap) return;
        if (mp.find(key) == mp.end()) {
            if (mp.size() >= cap) {
                int k = head->next->key;
                int idx = mp[k].second;
                Node* cur = mp[k].first;
                delNode(cur, idx);
                mp.erase(k);
            }
            Node* cur = new Node(key, value);
            mp[key] = make_pair(cur, 1);
            addNode(cur);
        }
        else {
            Node* cur = mp[key].first;
            cur->value = value;
            int idx = mp[key].second++;
            update(cur, idx);
        }
        
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */