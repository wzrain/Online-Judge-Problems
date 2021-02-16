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

// Just use two priority queues to track smaller and larger values. The top of the two queues are candidates 
// for the median. The smaller queue always contain n / 2 values.
class MedianFinder {
public:
    /** initialize your data structure here. */
    MedianFinder() {
        sz = 0;
    }
    
    void addNum(int num) {
        if (sz & 1) {
            // can directly push to large first, if num <= large.top(), it will be popped to small anyway
            if (num <= large.top()) small.push(num);
            else {
                large.push(num);
                small.push(large.top());
                large.pop();
            }
        }
        else {
            if (small.empty() || num >= small.top()) large.push(num);
            else {
                small.push(num);
                large.push(small.top());
                small.pop();
            }
        }
        sz++;
    }
    
    double findMedian() {
        if (sz & 1) return large.top();
        return (small.top() + large.top()) / 2.0;
    }
private:
    priority_queue<int> small;
    priority_queue<int, std::vector<int>, std::greater<int>> large;
    int sz;
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

 // follow-ups:
 // If all numbers are between 0-100, just use vectors to store count, and traverse the vector to find the 
 // median (still constant complexity). If 99% of the numbers are between 0-100, that means the median is 
 // surely between 0-100 (so this is also applicable for any percentage more than 50%), just track the counter 
 // for numbers less than 0 or larger than 100 respectively.