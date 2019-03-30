class LRUCache {
public:
  LRUCache(int capacity) {
    cap = capacity;
    size = 0;
    head = new node(-1, -1);
    rear = head;
  }

  int get(int key) {
    if (mp.find(key) == mp.end()) return -1;
    int res = mp[key]->val;
    if (mp[key] != rear) {
      remove(mp[key]);
      add(mp[key]);
    }
    return res;
  }

  void put(int key, int value) {
    if (mp.find(key) != mp.end()) { // details to ask
      get(key);
      mp[key]->val = value;
      return;
    }
    node* cur = new node(key, value);
    add(cur);
    mp[key] = cur;
    size++;
    if (size > cap) {
      node* p = head->next;
      mp.erase(p->key);
      remove(p);
      size--;
    }
  }
private:
  struct node {
    int key;
    int val;
    node* next;
    node* prev;
    node(int k = 0, int v = 0) : key(k), val(v), next(NULL), prev(NULL) {}
  };
  unordered_map<int, node*> mp;
  node *head, *rear;
  int size, cap;
  
  void remove(node* nd) {
    node* pr = nd->prev, *nx = nd->next;
    pr->next = nx;
    if (nx) nx->prev = pr;
  }
  
  void add(node* nd) {
    rear->next = nd;
    nd->prev = rear;
    rear = nd;
    rear->next = NULL;
  }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */