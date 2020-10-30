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