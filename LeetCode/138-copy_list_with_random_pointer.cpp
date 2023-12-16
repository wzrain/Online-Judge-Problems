/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// O(n) space with hash map
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* dummy = new Node(0);
        Node* cur = dummy;
        unordered_map<Node*, Node*> ump;
        Node* p = head;
        while (p) {
            if (ump.find(p) == ump.end()) {
                cur->next = new Node(p->val);
                cur = cur->next;
                ump[p] = cur;
            }
            else {
                cur->next = ump[p];
                cur = cur->next;
            }
            if (p->random){
                if(ump.find(p->random) == ump.end()) {
                    Node* rc = new Node(p->random->val);
                    cur->random = rc;
                    ump[p->random] = rc;
                }
                else {
                    cur->random = ump[p->random];
                }
            } 
            p = p->next;
        }
        return dummy->next;
    }
};

// O(1) space. Stitching the original and the copied linked list together and no hash map is needed.
class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* p = head;
        Node* dummy = new Node(0);
        Node* np = dummy;
        while (p) {
            Node* pcopy = new Node(p->val);
            np->next = pcopy;
            np = pcopy;
            p = p->next;
        }
        p = head;
        np = dummy;
        Node* npnxt = dummy->next;
        while (p) {
            Node* pnxt = p->next;
            np->next = p;
            p->next = npnxt;
            p = pnxt;
            np = npnxt;
            npnxt = npnxt->next;
        }
        p = dummy->next;
        while (p) {
            if (p->random) {
                p->next->random = p->random->next;
            }
            p = p->next->next;
        }
        p = dummy->next;
        np = dummy;
        while (p) {
            np->next = p->next;
            if (p->next) p->next = p->next->next;
            np = np->next;
            p = p->next;
        }
        return dummy->next;
    }
};