/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
// non-recursive
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    ListNode* head = new ListNode(0), *h = head;
    ListNode *p = l1, *q = l2;
    while (p && q) {
      if (p->val > q->val) {
        h->next = new ListNode(q->val);
        q = q->next;
      }
      else {
        h->next = new ListNode(p->val);
        p = p->next;
      }
      h = h->next;
    }
    // while (p) {
    //   h->next = new ListNode(p->val);
    //   p = p->next;
    //   h = h->next;
    // }
    // while (q) {
    //   h->next = new ListNode(q->val);
    //   q = q->next;
    //   h = h->next;
    // }
    if (p) h->next = p;
    else if (q) h->next = q;
    return head->next;
  }
};

// recursive
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
  ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
    if (!l1) return l2;
    if (!l2) return l1;
    ListNode* head;
    if (l1->val > l2->val) {
      head = new ListNode(l2->val);
      head->next = mergeTwoLists(l1, l2->next);
    }
    else {
      head = new ListNode(l1->val);
      head->next = mergeTwoLists(l1->next, l2);
    }
    return head;
  }
};