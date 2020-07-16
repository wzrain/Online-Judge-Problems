// The key is that every modification only change by 1,
// so every time we only need to do some position changing.
// To make it O(1) we need double-linked list to enable
// constant insertion and delete. One idea is to track every
// "node" instead of just integers.
// Another double-linked list is applied in order to deal
// with nodes of the same value. This is actually a counterpart
// of a "bucket". On the first double-linked list there is 
// only one "rep" node for each value.
class AllOne {
private:
    struct node {
        string key;
        int val;
        node* prev;
        node* next;
        node* psame;
        node* nsame;
        node(string k, int v) : key(k), val(v), prev(NULL), next(NULL), psame(NULL), nsame(NULL) {}
    };
    unordered_map<string, node*> kv;
    unordered_map<int, node*> rep;
    node* head;
    node* rear;
    
    void insertIntoSame(node* nd, int curval) {
        nd->psame = rep[curval];
        nd->nsame = rep[curval]->nsame;
        if (rep[curval]->nsame) rep[curval]->nsame->psame = nd;
        rep[curval]->nsame = nd;
    }
    
    void insertNewValAfter(node* nd, node* pre, int curval) {
        nd->next = pre->next;
        nd->prev = pre;
        pre->next->prev = nd;
        pre->next = nd;
        rep[curval] = nd;
    }
    
    void insertNewValBefore(node* nd, node* nxt, int curval) {
        nd->next = nxt;
        nd->prev = nxt->prev;
        nxt->prev->next = nd;
        nxt->prev = nd;
        rep[curval] = nd;
    }
    
    void changeRep(int preval) {
        node* nd = rep[preval];
        nd->nsame->prev = nd->prev;
        nd->nsame->next = nd->next;
        nd->prev->next = nd->nsame;
        nd->next->prev = nd->nsame;
        nd->nsame->psame = NULL;
        rep[preval] = nd->nsame;
        nd->nsame = nd->psame = NULL;
    }
    
    void delInLink(node* nd) {
        nd->prev->next = nd->next;
        nd->next->prev = nd->prev;
    }
    
    void delInSame(node* nd) {
        nd->psame->nsame = nd->nsame;
        if (nd->nsame) nd->nsame->psame = nd->psame;
        nd->psame = nd->nsame = NULL;
    }
public:
    /** Initialize your data structure here. */
    AllOne() {
        head = new node("", 0);
        rear = new node("", INT_MAX);
        head->next = rear;
        rear->prev = head;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (kv.find(key) == kv.end()) {
            node* nd = new node(key, 1);
            kv[key] = nd;
            
            if (rep.find(1) == rep.end()) {
                insertNewValAfter(nd, head, 1);
            }
            else insertIntoSame(nd, 1);
        }
        else {
            node* nd = kv[key];
            int preval = nd->val;
            int curval = ++(nd->val);
            
            if (nd == rep[preval]) {
                if (nd->nsame) {
                    changeRep(preval);
                    if (rep.find(curval) == rep.end()) {
                        insertNewValAfter(nd, rep[preval], curval);
                    }
                    else insertIntoSame(nd, curval);
                }
                else {
                    rep.erase(preval);
                    if (rep.find(curval) == rep.end()) rep[curval] = nd;
                    else {
                        delInLink(nd);
                        insertIntoSame(nd, curval);
                    }
                }
            }
            else {
                delInSame(nd);
                if (rep.find(curval) == rep.end()) {
                    insertNewValAfter(nd, rep[preval], curval);
                }
                else insertIntoSame(nd, curval);
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (kv.find(key) == kv.end()) return;
        node* nd = kv[key];
        int preval = nd->val;
        int curval = --(nd->val);
        if (!curval) kv.erase(key);
        if (nd == rep[preval]) {
            if (nd->nsame) {
                changeRep(preval);
                if (curval && rep.find(curval) == rep.end()) {
                    insertNewValBefore(nd, rep[preval], curval);
                }
                else if (curval) {
                    insertIntoSame(nd, curval);
                }
            }
            else {
                rep.erase(preval);
                if (curval && rep.find(curval) == rep.end()) rep[curval] = nd;
                else {
                    delInLink(nd);
                    if (curval) insertIntoSame(nd, curval);
                }
            }
        }
        else {
            delInSame(nd);
            if (curval && rep.find(curval) == rep.end()) {
                insertNewValBefore(nd, rep[preval], curval);
            }
            else if (curval) {
                insertIntoSame(nd, curval);
            }
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        return rear->prev->key;
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        return head->next->key;
    }
};

/**
 * Your AllOne object will be instantiated and called as such:
 * AllOne* obj = new AllOne();
 * obj->inc(key);
 * obj->dec(key);
 * string param_3 = obj->getMaxKey();
 * string param_4 = obj->getMinKey();
 */