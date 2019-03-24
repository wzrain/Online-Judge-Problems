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
  ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
    vector<int> v1, v2;
    ListNode* p1 = l1, *p2 = l2;
    while (p1) {
      v1.push_back(p1->val);
      p1 = p1->next;
    }
    while (p2) {
      v2.push_back(p2->val);
      p2 = p2->next;
    }
    ListNode *q, *p = new ListNode(0);
    int addtmp = 0;
    while (!v1.empty() && !v2.empty()) {
      p->val = v1.back() + v2.back() + addtmp;
      addtmp = p->val / 10;
      p->val %= 10;
      v1.pop_back();
      v2.pop_back();
      q = new ListNode(0);
      q->next = p;
      p = q;
    }
    while (!v1.empty()) {
      p->val = v1.back() + addtmp;
      addtmp = p->val / 10;
      p->val %= 10;
      v1.pop_back();
      q = new ListNode(0);
      q->next = p;
      p = q;
    }
    while (!v2.empty()) {
      p->val = v2.back() + addtmp;
      addtmp = p->val / 10;
      p->val %= 10;
      v2.pop_back();
      q = new ListNode(0);
      q->next = p;
      p = q;
    }
    if (addtmp) p->val = 1; 
    return p->val ? p : p->next;
  }
};