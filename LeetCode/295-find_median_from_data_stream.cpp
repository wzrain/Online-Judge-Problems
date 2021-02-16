// Use a map to sort the numbers, and a linked list to track its corresponding position. The map stores the 
// first node of that value, and every time only insert before that first node. Adjust the median node every time.
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        sz = 0;
        rear = new Node();
        cur = rear;
    }
    
    void addNum(int num) {
        Node* nx;
        Node* nw = new Node(num);
        if (mp.find(num) != mp.end()) {
            nx = mp[num];
            mp[num] = nw;
        }
        else {
            mp[num] = nw;
            auto it = mp.find(num);
            if (++it != mp.end()) nx = it->second;
            else nx = rear;
        }
        insertBefore(nw, nx);
        if (num > cur->val && !(sz & 1)) cur = cur->next;
        else if (num <= cur->val && (!sz || (sz & 1))) cur = cur->prev;
        sz++;
    }
    
    double findMedian() {
        if (sz & 1) return cur->val;
        return (cur->val + cur->next->val) / 2.0;
    }
private:
    struct Node {
        int val;
        Node* next;
        Node* prev;
        Node(int v = INT_MAX) : val(v), next(NULL), prev(NULL) {}
    };
    Node* cur, *rear;
    map<int, Node*> mp;
    int sz;
    
    void insertBefore(Node* nw, Node* nx) {
        nw->next = nx;
        nw->prev = nx->prev;
        if (nx->prev) nx->prev->next = nw;
        nx->prev = nw;
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */